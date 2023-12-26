/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 06:41:00 by randre            #+#    #+#             */
/*   Updated: 2023/12/26 11:47:46 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_texture(t_game *game, char *path, int i)
{
	xpm_t		*raw_text;
	mlx_image_t *pro_text;
	
	raw_text = mlx_load_xpm42(path);
	game->sprites[i] = NULL;
	if (!raw_text)
	{
		write(2, "Error\nTexture loading failed\n", 29);
		return ;
	}
	pro_text = mlx_texture_to_image(game->mlx, raw_text);
	if (!pro_text)
	{
		write(2, "Error\nTexture loading failed\n", 29);
		return ;
	}
	game->sprites[i] = pro_text;
}

void	init_textures(t_game *game)
{
	int	i;

	i = -1;
	load_texture(game, "assets/ground.xpm42", 0);
	load_texture(game, "assets/tree.xpm42", 1);
	load_texture(game, "assets/collectible.xpm42", 2);
	load_texture(game, "assets/exit.xpm42", 3);
	load_texture(game, "assets/player.xpm42", 4);
	while (++i < 5)
		if (!game->sprites[i])
		{
			exit(1);
		}
}