/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:35:50 by randre            #+#    #+#             */
/*   Updated: 2023/12/29 11:30:37 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_sprites(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_delete_image(game->mlx, game->sprites[i]);
}

void	clean_map(char ***map)
{
	int	i;

	i = -1;
	while (map[0][++i])
		free(map[0][i]);
	free(map[0]);
}

void	clean_close(t_game *game)
{
	if (game->ref_map)
		clean_map(&game->ref_map);
	if (game->map)
		clean_map(&game->map);
	clean_sprites(game);
	mlx_terminate(game->mlx);
}

void	ft_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clean_close(game);
	exit(0);
}
