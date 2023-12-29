/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:49:33 by randre            #+#    #+#             */
/*   Updated: 2023/12/29 11:26:24 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_press(struct mlx_key_data keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode.key == MLX_KEY_ESCAPE)
	{
		clean_close(game);
		exit(0);
	}
	else if (keycode.key == MLX_KEY_W && (keycode.action == MLX_REPEAT
			|| keycode.action == MLX_RELEASE))
		w_move(game);
	else if (keycode.key == MLX_KEY_S && (keycode.action == MLX_REPEAT
			|| keycode.action == MLX_RELEASE))
		s_move(game);
	else if (keycode.key == MLX_KEY_D && (keycode.action == MLX_REPEAT
			|| keycode.action == MLX_RELEASE))
		d_move(game);
	else if (keycode.key == MLX_KEY_A && (keycode.action == MLX_REPEAT
			|| keycode.action == MLX_RELEASE))
		a_move(game);
	check_pos(game);
}
