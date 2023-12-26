/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:54:59 by randre            #+#    #+#             */
/*   Updated: 2023/12/26 07:02:36 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_ground(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->lines)
	{
		x = -1;
		while (++x < game->rows)
			if (game->map[y][x] != '1')
			{
				mlx_image_to_window(game->mlx, game->sprites[0], x * game->img_pxl, y
					* game->img_pxl);
			}
	}
}

void	init_display(t_game *game)
{
	display_ground(game);
}