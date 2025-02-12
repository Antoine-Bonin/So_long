/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:20:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/12 17:22:43 by antbonin         ###   ########.fr       */
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

int	check_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	return (0);
}

int	handle_destroy(t_game *game)
{
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
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (check_extension(av[1]) != 0)
		return (1);
	if (setup_game(&game, av[1]) != 0)
		return (1);
	draw_map(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, handle_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, handle_destroy,
		&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
