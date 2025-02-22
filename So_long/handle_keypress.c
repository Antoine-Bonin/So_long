/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:57:51 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/22 15:36:27 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "../minilibx-linux/mlx.h"
#include "so_long.h"
#include <X11/keysym.h>
#include <stdlib.h>

int	move_player(int keysym, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->player_x;
	old_y = game->player_y;
	if (keysym == XK_w || keysym == XK_Up)
		game->player_y--;
	else if (keysym == XK_s || keysym == XK_Down)
		game->player_y++;
	else if (keysym == XK_a || keysym == XK_Left)
		game->player_x--;
	else if (keysym == XK_d || keysym == XK_Right)
		game->player_x++;
	else
		return (1);
	if (game->map[game->player_y][game->player_x] == '1'
		|| (game->map[game->player_y][game->player_x] == 'E'
			&& game->collectibles_remaining != 0))
	{
		game->player_x = old_x;
		game->player_y = old_y;
		game->total_moves--;
	}
	return (0);
}

int	close_check(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == 17)
	{
		cleanup_textures(game);
		free(game);
		ft_printf("You left the game\n");
		exit(0);
	}
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{
	close_check(keysym, game);
	if (move_player(keysym, game) == 0)
	{
		game->total_moves++;
		draw_map(game);
		ft_printf("total number of moves : %d\n", game->total_moves);
	}
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->collectibles_remaining--;
	}
	if (game->collectibles_remaining == 0)
	{
		if (game->map[game->player_y][game->player_x] == 'E')
		{
			cleanup_textures(game);
			free(game);
			ft_printf("You won\n");
			exit(0);
		}
	}
	return (0);
}
