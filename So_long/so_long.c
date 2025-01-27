/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:20:15 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/27 15:23:32 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ssize_t	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	size_t	lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nopening file");
		return (0);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (lines == 0)
	{
		perror("Error\nreading file");
		return (-1);
	}
	return (lines);
}

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nopening file");
	}
	return (fd);
}

int	init_game(t_game *game, const char *filename)
{
	int	fd;

	fd = open_file(filename);
	if (fd == -1)
		return (-1);
	if (count_lines(filename) < 3)
		return (-1);
	game->map = load_map(fd, count_lines(filename));
	if (!game->map)
		return (1);
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = count_lines(filename);
	game->collectibles_remaining = 0;
	game->total_moves = 0;
	game->reached_exit = 0;
	if (validate_map(game, count_lines(filename), fd) != 0)
		return (1);
	if (init_window_and_textures(game) != 0)
		return (1);
	return (0);
}

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
		ft_printf("Error\n you must choose a map");
		return (1);
	}
	if (init_game(&game, av[1]) != 0)
		return (1);
	init_values(&game);
	flood_fill(game.map, game.player_x, game.player_y, &game);
	if (game.reached_exit == 0)
	{
		perror("Error\n there's no path to take");
		free_tab(game.map);
		cleanup_textures(&game);
		return (1);
	}
	draw_map(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, handle_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, handle_destroy,
		&game);
	mlx_loop(game.mlx_ptr);
	// free_tab(game.map);
	// cleanup_textures(&game);
	return (0);
}
