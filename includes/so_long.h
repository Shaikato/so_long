/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:30:14 by randre            #+#    #+#             */
/*   Updated: 2023/12/26 11:50:51 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_game
{
	void		*mlx;
	void		*win;
	mlx_image_t	*sprites[8];
	char		*addr;
	char		**map;
	char		**ref_map;
	int			lines;
	int			rows;
	int			img_pxl;
	int			collectables;
	int			total_collectables;
	int			moves;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
}				t_game;

/*		Verification/Build		*/
void	file_verif(char *path);
void	build_map(t_game *game, char *path);
void	map_check(t_game *game);
void	get_pos(t_game *game);
void	path_check(t_game *game);

/*		MLX Init/Window			*/
void	init_game(t_game *game);
void	init_textures(t_game *game);
void	init_display(t_game *game);
void	display_player(t_game *game);

/*		Key_hook/Events			*/
void	key_press(struct mlx_key_data keycode, void *param);

#endif
