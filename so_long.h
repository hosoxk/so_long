/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:36:44 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/09/18 15:13:09 by yde-rudd         ###   ########.fr       */
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
	int		on_exit;
	int		moves;
}	t_player;

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
	int		total_collectibles;
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

typedef struct s_bfs_state
{
	t_point *queue;
	int **visited;
	int front;
	int rear;
	int collectibles_found;
	int exit_reached;
}	t_bfs_state;

//initializing
void	init_game(t_game *game, const char *filename);
void	init_mlx(t_game *game);
void	init_images(t_game *game);
void	setup_hook_events(t_game *game);

//reading and checking map
t_map	read_map(const char *filename);
bool	check_illegal_characters(t_map *map);
bool	is_map_valid(t_game *game);
bool	bfs(t_map *map, t_point start, int total_collectibles);
void	explore_adjacent(t_map *map, t_point *queue,
			int **visited, t_point current, int *rear);
bool	is_valid(int x, int y, t_map *map, int **visited);
int		count_elements(t_map *map, char element);
int		count_collectibles(t_map *map);
int		count_player(t_map *map);
int		count_exit(t_map *map);
t_point	find_player_pos(t_game *game);

//in-game
void	draw_map(t_game *game);
void	draw_tile(t_game *game, int x, int y, char tile);
void	update_player(t_game *game, int keycode);
int		check_key(int keycode, t_game *game);

//free data
void	destroy_game_resources(t_game *game);
void	free_map(t_map *map);

//print utils
void	print_allocated_memory(t_map *map);
void	print_map_data(t_map *map);

#endif
