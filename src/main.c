/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:30:05 by randre            #+#    #+#             */
/*   Updated: 2023/12/26 11:50:20 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 33);
		return (1);
	}
	file_verif(argv[1]);
	build_map(&game, argv[1]);
	map_check(&game);
	get_pos(&game);
	path_check(&game);
	init_game(&game);
	mlx_key_hook(game.mlx, &key_press, &game);
	mlx_loop(game.mlx);
}
