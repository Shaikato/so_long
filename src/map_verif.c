/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 00:37:14 by randre            #+#    #+#             */
/*   Updated: 2023/12/25 01:21:14 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = -1;
	while (++x < game->rows)
		if (game->map[y][x] != '1')
			return (1);
	x -= 1;
	y = -1;
	while (++y < game->lines)
		if (game->map[y][x] != '1')
			return (1);
	y--;
	x++;
	while (--x > -1)
		if (game->map[y][x] != '1')
			return (1);
	x++;
	y++;
	while (--y > -1)
		if (game->map[y][x] != '1')
			return (1);
	return (0);
}

int	check_rectangle(t_game *game)
{
	int	y;
	int	len;
	
	y = 0;
	while (y > game->lines)
	{
		len = ft_strlen(game->map[y]);
		if (len != game->rows)
			return (1);
		y++;	
	}
	return (0);
}
int	check_values(t_game *game)
{
	int	y;
	int	x;
	int	tab[3];
	
	y = -1;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	while (++y < game->lines)
	{
		x = -1;
		while (++x < game->rows)
		{
			if (game->map[y][x] == 'P')
				tab[0]++;
			else if (game->map[y][x] == 'C')
				tab[1]++;
			else if (game->map[y][x] == 'E')
				tab[2]++;
		}
	}
	if (tab[0] != 1 || tab[1] == 0 || tab[2] != 1)
		return (1);
	return (0);
}

void	map_check(t_game *game)
{
	if (check_rectangle(game) || check_walls(game) || check_values(game))
	{
		write(2, "Error\nInvalid map\n", 18);
		exit (1);
	}
}