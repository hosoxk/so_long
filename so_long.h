/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:36:44 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/07 14:42:54 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "stdbool.h"

# define TILE_SIZE 64
# define FLOOR '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define ESC_KEY 65307
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define UP_ARROW 65362
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define Q_KEY 113
# define PLAYER_IMAGE_PATH "./textures/chicken.xpm"
# define COLLECTIBLE_IMAGE_PATH "./textures/Egg_item.xpm"
# define EXIT_IMAGE_PATH "./textures/Free_Chicken_House.xpm"
# define FLOOR_IMAGE_PATH "./textures/floor.xpm"
# define WALL_IMAGE_PATH "./textures/wall.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	t_point	position;
	int		collected_collectibles;
	bool	on_exit;
	int		moves;
}	t_player;

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
	int		total_collectibles;
	int		total_exits;
	int		total_players;
}	t_map;

typedef struct s_game
{
	t_player	player;
	t_map		map;
	void		*mlx;
	void		*window;
	void		*wall_img;
	void		*player_img;
	void		*floor_img;
	void		*collectible_img;
	void		*exit_img;
	int			img_width;
	int			img_height;
}	t_game;

//initializing
void	init_game(t_game *game, const char *filename);
void	init_map(t_map *map);
void	init_mlx(t_game *game);
void	init_images(t_game *game);
void	set_up_hooks(t_game *game);

//reading and checking map
t_map	read_map(const char *filename);
bool	is_map_valid(t_map *map);
t_point	find_player_pos(t_map *map);
bool	is_map_enclosed(t_map *map);

//algorithm
bool	checking_algo(char **data, t_point start);

//in-game
void	draw_map(t_game *game);
void	draw_tile(t_game *game, int x, int y, char tile);
void	update_player(t_game *game, int new_x, int new_y);

//free data
void	destroy_game_resources(t_game *game);
void	free_gnl(int fd, char *line);
void	free_mlx(t_game *game);
int		close_window(t_game *game);

//print utils
void	print_map_data(char **data);

#endif
