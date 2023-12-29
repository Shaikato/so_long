/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:48:27 by randre            #+#    #+#             */
/*   Updated: 2023/12/29 11:22:44 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*void	erase_player(t_game *game)
{
	
}*/

void	w_move(t_game *game)
{
	if (check_cross(game->player_x, game->player_y - 1, game))
	{
		game->moves++;
		game->sprites[4]->instances[0].y -= 64;
		ft_printf("Moves : %d\n", game->moves);
		game->player_y--;
	}
}

void	s_move(t_game *game)
{
	if (check_cross(game->player_x, game->player_y + 1, game))
	{
		game->moves++;
		game->sprites[4]->instances[0].y += 64;
		ft_printf("Moves : %d\n", game->moves);
		game->player_y++;
	}
}

void	a_move(t_game *game)
{
	if (check_cross(game->player_x - 1, game->player_y, game))
	{
		game->moves++;
		game->sprites[4]->instances[0].x -= 64;
		ft_printf("Moves : %d\n", game->moves);
		game->player_x--;
	}
}

void	d_move(t_game *game)
{
	if (check_cross(game->player_x + 1, game->player_y, game))
	{
		game->moves++;
		game->sprites[4]->instances[0].x += 64;
		ft_printf("Moves : %d\n", game->moves);
		game->player_x++;
	}
}
