/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:41:13 by randre            #+#    #+#             */
/*   Updated: 2023/12/25 05:10:08 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	name_check(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
		return (ft_putstr_fd("Error\nWrong file extension\n", 2), 1);
	return (0);
}

static int	file_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (ft_putstr_fd("Error\nFile doesn't exist\n", 2), 1);
	}
	close(fd);
	return (0);
}

void	file_verif(char *path)
{
	if (file_exist(path) || name_check(path))
		exit(1);
}