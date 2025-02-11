/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:40:54 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/11 14:39:16 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../gnl/get_next_line.h"
#include "so_long.h"
#include "fcntl.h"

ssize_t	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	size_t	lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error\n", 2);
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
		ft_putendl_fd("Error\n", 2);
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
		ft_putendl_fd("Error\n", 2);
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
	game->found_collectibles = 0;
	if (validate_map(game, count_lines(filename), fd) != 0)
		return (1);
	if (init_window_and_textures(game) != 0)
		return (1);
	return (0);
}

int	check_map_valid(t_game *game, char **map_copy)
{
	flood_fill(map_copy, game->player_x, game->player_y, game);
	if (game->reached_exit == 0
		|| game->found_collectibles != game->collectibles_remaining)
	{
		ft_putendl_fd("Error\n", 2);
		free_tab(map_copy);
		cleanup_textures(game);
		return (1);
	}
	free_tab(map_copy);
	return (0);
}

int	setup_game(t_game *game, char *map_path)
{
	char	**map_copy;

	if (init_game(game, map_path) != 0)
		return (1);
	init_values(game);
	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
		return (1);
	if (check_map_valid(game, map_copy) != 0)
		return (1);
	return (0);
}
