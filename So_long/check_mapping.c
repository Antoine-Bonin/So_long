/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:35:36 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/17 18:07:30 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../libft/ressource/libft.h"
#include "so_long.h"

size_t	init_count(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				game->count_player++;
			else if (game->map[y][x] == 'E')
				game->count_exit++;
			else if (game->map[y][x] == 'C')
				game->count_collectible++;
			x++;
		}
		y++;
	}
	if (game->count_player != 1 || game->count_exit != 1
		|| game->count_collectible < 1)
		return (ft_putendl_fd("Error\nMap must have exactly 1 player, \
1 exit and at least 1 collectible", 2), 1);
	return (0);
}

size_t	check_characters(char **tab, size_t lines)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (tab[y] && y < lines)
	{
		x = 0;
		while (tab[y][x])
		{
			if (ft_strchr(INVALID, tab[y][x]) != NULL)
			{
				ft_putendl_fd("Error\nInvalid character in map", 2);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	check_mapping(char **tab, size_t lines)
{
	size_t	y;

	y = 0;
	while (tab[y] && y < lines)
	{
		if (ft_strlen(tab[0]) != ft_strlen(tab[y]))
		{
			ft_putendl_fd("Error\nMap must be rectangular", 2);
			return (1);
		}
		y++;
	}
	return (0);
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map_height || y < 0 || y >= game->map_width)
		return ;
	if (map[x][y] == '1' || map[x][y] == '2')
		return ;
	if (map[x][y] == 'E')
	{
		game->reached_exit = 1;
		return ;
	}
	if (map[x][y] == 'C')
	{
		game->found_collectibles++;
		map[x][y] = '2';
	}
	if (map[x][y] != 'E')
		map[x][y] = '2';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

int	validate_map(t_game *game, size_t lines, int fd)
{
	game->count_player = 0;
	game->count_exit = 0;
	game->count_collectible = 0;
	if ((check_mapping(game->map, lines) + check_characters(game->map, lines)
			+ init_count(game) + check_wall_top(game) + check_wall_bot(game,
				lines) + check_wall(game, lines)) != 0)
	{
		free_tab(game->map);
		close(fd);
		return (1);
	}
	return (0);
}
