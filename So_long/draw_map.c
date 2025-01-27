/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:55:59 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:45 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

void	init_values(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles_remaining++;
			else if (game->map[y][x] == 'E')
			{
				game->door_x = x;
				game->door_y = y;
			}
			else if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	draw_cell(t_game *game, int x, int y, int cell_size)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_img, x
		* cell_size, y * cell_size);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_img, x
			* cell_size, y * cell_size);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collectible_img, x * cell_size, y * cell_size);
	else if (game->map[y][x] == 'E')
	{
		if (game->collectibles_remaining == 0)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->exit_img, x * cell_size, y * cell_size);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->door_open, x * cell_size, y * cell_size);
	}
}

void	draw_map(t_game *game)
{
	int	cell_size;
	int	x;
	int	y;

	cell_size = 80;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_cell(game, x, y, cell_size);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->character_img,
		game->player_x * cell_size, game->player_y * cell_size);
}
