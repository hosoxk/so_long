/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:47:04 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/04 18:53:55 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_player(t_player *player)
{
	player->position.x = 0;
	player->position.y = 0;
	player->on_exit = 0;
	player->moves = 0;
}

void	init_game(t_game *game, const char *filename)
{
	init_player(&game->player);
	game->map = read_map(filename);
	game->mlx = 0;
	game->window = 0;
	game->wall_img = 0;
	game->player_img = 0;
	game->floor_img = 0;
	game->collectible_img = 0;
	game->exit_img = 0;
	game->img_width = 0;
	game->img_height = 0;
}

void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->data = NULL;
	map->total_collectibles = 0;
	map->total_exits = 0;
	map->total_players = 0;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error: could not initialize MLX\n");
		exit(1);
	}
	game->window = mlx_new_window(game->mlx, TILE_SIZE * game->map.width,
			TILE_SIZE * game->map.height, "so_long");
	if (!game->window)
	{
		perror("Error:\ncould not create a window\n");
		exit(1);
	}
}

void	init_images(t_game *game)
{
	game->floor_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->floor_img)
		return (ft_printf("Error:\ninitializing floor image\n"),
			ft_freearr(game->map.data), free_mlx(game), exit(1));
	game->wall_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->wall_img)
		return (ft_printf("Error:\ninitializing wall image\n"),
			ft_freearr(game->map.data), free_mlx(game), exit(1));
	game->player_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->player_img)
		return (ft_printf("Error:\ninitializing player image\n"),
			ft_freearr(game->map.data), free_mlx(game), exit(1));
	game->collectible_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->collectible_img)
		return (ft_printf("Error:\ninitializing collectible image\n"),
			ft_freearr(game->map.data), free_mlx(game), exit(1));
	game->exit_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!game->exit_img)
		return (ft_printf("Error:\ninitializing exit image\n"),
			ft_freearr(game->map.data), free_mlx(game), exit(1));
}
