/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:31:56 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/23 11:33:48 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

size_t	check_wall_top(t_game *game)
{
	size_t	x;

	x = 0;
	while (game->map[0][x] != '\0' && game->map[0][x] != '\n')
	{
		if (game->map[0][x] != '1')
			return (perror("Error\nWall missing on top\n"), 1);
		x++;
	}
	return (0);
}

size_t	check_wall_bot(t_game *game, size_t lines)
{
	size_t	x;

	x = 0;
	while (game->map[lines - 1][x] != '\0' && game->map[lines - 1][x] != '\n')
	{
		if (game->map[lines - 1][x] != '1')
		{
			perror("Error\nWall missing on bottom\n");
			return (1);
		}
		x++;
	}
	return (0);
}

size_t	check_wall(t_game *game, size_t lines)
{
	size_t	y;

	y = 0;
	while (y < lines)
	{
		if (game->map[y][0] != '1')
		{
			perror("Error\nWall missing on left\n");
			return (1);
		}
		y++;
	}
	y = 0;
	while (y < lines)
	{
		if (game->map[y][ft_strlen(game->map[y]) - 1] != '1')
		{
			perror("Error\nWall missing on right\n");
			return (1);
		}
		y++;
	}
	return (0);
}
