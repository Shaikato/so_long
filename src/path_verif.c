/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 05:38:29 by randre            #+#    #+#             */
/*   Updated: 2023/12/26 06:07:11 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_cross(int y, int x, t_game *game)
{
	if (x < 0 || x > game->rows - 1)
		return (0);
	else if (y < 0 || y > game->lines - 1)
		return (0);
	else if (game->ref_map[y][x] != '1')
		return (1);
	return (0);
}

void	true_bounds(t_game *game, int x, int y)
{
	if (check_cross(y, x, game))
	{
		if (game->ref_map[y][x] == '.')
			return ;
		if (game->ref_map[y][x] == 'C')
			game->total_collectables++;
		game->ref_map[y][x] = '.';
		true_bounds(game, x - 1, y);
		true_bounds(game, x + 1, y);
		true_bounds(game, x, y + 1);
		true_bounds(game, x, y - 1);
	}
	return ;
}

void	path_check(t_game *game)
{
	int	y;
	int	x;

	true_bounds(game, game->player_x, game->player_y);
	y = -1;
	while (++y < game->lines)
	{
		x = -1;
		while (++x < game->rows)
		{
			if ((game->map[y][x] == 'C' || game->map[y][x] == 'E') && game->ref_map[y][x] != '.')
			{
				write(2, "Error\nNo possible path\n", 23);
				exit (1);
			}
		}
	}
}
