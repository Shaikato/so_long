/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 00:00:45 by randre            #+#    #+#             */
/*   Updated: 2023/12/26 06:54:52 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->img_pxl = 32;
	game->mlx = mlx_init(game->img_pxl * game->rows, 
		game->img_pxl * game->lines, "so_long", true);
	init_textures(game);
	init_display(game);
}