/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 00:01:05 by randre            #+#    #+#             */
/*   Updated: 2023/12/29 11:30:59 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	empty_handler(char *line)
{
	free(line);
	write(2, "Error\nEmpty map\n", 16);
	exit (1);
}

void	get_pos(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->lines)
	{
		x = -1;
		while (++x < game->rows)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
		}
	}
}

void	char_verif(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->lines)
	{
		x = 0;
		while (x < game->rows)
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
			&& game->map[y][x] != 'C' && game->map[y][x] != 'P'
			&& game->map[y][x] != 'E')
			{
				write(2, "Error\nInvalid map\n", 18);
				exit (1);
			}
			x++;
		}
		y++;
	}
}

void	build_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	char	*entire_map;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		empty_handler(line);
	game->lines = 0;
	game->rows = ft_strlen(line) - 1;
	entire_map = ft_calloc(1, 1);
	while (line)
	{
		entire_map = ft_strjoin(entire_map, line);
		game->lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->map = ft_split(entire_map, '\n');
	game->ref_map = ft_split(entire_map, '\n');
	free(entire_map);
	char_verif(game);
}
