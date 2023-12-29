/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:21:36 by randre            #+#    #+#             */
/*   Updated: 2023/12/29 11:29:33 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_pos(t_game *game)
{
	int	i;

	i = -1;
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->collectables++;
		game->map[game->player_y][game->player_x] = 'X';
		while (++i < (int)game->sprites[2]->count)
		{
			if (game->sprites[2]->instances[i].x == game->player_x * 64
				&& game->sprites[2]->instances[i].y == game->player_y * 64)
				game->sprites[2]->instances[i].enabled = false;
		}
	}
	else if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collectables == game->total_collectables)
	{
		ft_printf("Congratulations ! You finished with %d moves !\n",
			game->moves);
		clean_close(game);
		exit(0);
	}
}
