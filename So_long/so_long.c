/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:20:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/10 17:47:18 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../libft/ressource/libft.h"
#include "../minilibx-linux/mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <stdlib.h>

int	handle_destroy(t_game *game)
{
	free_tab(game->map);
	cleanup_textures(game);
	ft_printf("You left the game");
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_putendl_fd("Error\n", 2);
		return (1);
	}
	if (setup_game(&game, av[1]) != 0)
		return (1);
	draw_map(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, handle_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, handle_destroy,
		&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
