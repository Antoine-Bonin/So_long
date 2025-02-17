/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:10 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/17 17:58:02 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define INVALID "23456789abcdefghijklmnopqrstuvwxyzABDFGHIJKLMNOQRSTUVWXYZ "

# ifndef MAX_WIDTH
#  define MAX_WIDTH 3840
# endif

# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 2160
# endif

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
	void	*wall_img;
	void	*floor_img;
	int		img_width;
	int		img_height;
	void	*collectible_img;
	void	*character_img;
	int		collectibles_remaining;
	void	*door_open;
	int		total_moves;
	void	*exit_img;
	int		count_player;
	int		count_exit;
	int		count_collectible;
	int		found_collectibles;
	int		reached_exit;
}			t_game;

/************************map************************************/

char		**mapping(int fd, size_t lines);
char		**load_map(int fd, size_t lines);
char		**copy_map(char **map, int height);
void		draw_map(t_game *game);

/************************mlx*************************************/

int			handle_keypress(int keysym, t_game *game);
void		init_values(t_game *game);
int			init_window_and_textures(t_game *game);
int			cleanup_textures(t_game *game);

/*************************parsing*********************************/

int			validate_map(t_game *game, size_t lines, int fd);
size_t		check_wall_top(t_game *game);
size_t		check_wall_bot(t_game *game, size_t lines);
size_t		check_wall(t_game *game, size_t lines);
void		flood_fill(char **map, int x, int y, t_game *game);

/***************************init************************************/

int			check_map_valid(t_game *game, char **map_copy);
int			setup_game(t_game *game, char *map_path);

/*******************************************************************/
#endif