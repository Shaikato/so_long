/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:29:15 by randre            #+#    #+#             */
/*   Updated: 2023/12/26 11:32:05 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_player(t_game *game)
{
	mlx_image_to_window(game->mlx, game->sprites[4], game->player_x * game->img_pxl, game->player_y
					* game->img_pxl);
}