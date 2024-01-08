/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 00:00:45 by randre            #+#    #+#             */
/*   Updated: 2024/01/08 12:25:19 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->img_pxl = 64;
	game->mlx = mlx_init(game->img_pxl * game->rows,
			game->img_pxl * game->lines, "so_long", false);
	game->moves = 0;
	game->collectables = 0;
	init_textures(game);
	init_display(game);
	game->total_collectables = (int)game->sprites[2]->count;
}
