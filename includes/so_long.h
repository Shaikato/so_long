/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:30:14 by randre            #+#    #+#             */
/*   Updated: 2023/12/25 00:51:40 by randre           ###   ########.fr       */
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
	int			current_x;
	int			current_y;
	int			end_x;
	int			end_y;
}				t_game;

/*		Verification/Build		*/
void	file_verif(char *path);
void	build_map(t_game *game, char *path);
void	map_check(t_game *game);

#endif
