/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/01/24 17:52:47 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define INVALID "23456789abcdefghijklmnopqrstuvwxyzABDFGHIJKLMNOQRSTUVWXYZ "
# include "unistd.h"

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		player2_x;
	int		player2_y;
	void	*wall_img;
	void	*floor_img;
	int		img_width;
	int		img_height;
	void	*collectible_img;
	void	*character_img;
	int		collectibles_remaining;
	int		door_x;
	int		door_y;
	void	*door_open;
	int		total_moves;
	void	*exit_img;
	int		count_player;
	int		count_exit;
	int		count_collectible;
	int		found_exit;
	int		found_collectibles;
	int		reached_exit;
}			t_game;

char		**mapping(int fd, size_t lines);
int			free_tab(char **tab);
int			validate_map(t_game *game, size_t lines, int fd);
char		**load_map(int fd, size_t lines);
void		draw_map(t_game *game);
int			handle_keypress(int keysym, t_game *game);
void		init_values(t_game *game);
int			init_window_and_textures(t_game *game);
int			cleanup_textures(t_game *game);
size_t		check_wall_top(t_game *game);
size_t		check_wall_bot(t_game *game, size_t lines);
size_t		check_wall(t_game *game, size_t lines);
void		flood_fill(char **map, int x, int y, t_game *game);
#endif