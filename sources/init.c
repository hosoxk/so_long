/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:47:04 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/01 12:50:02 by yde-rudd         ###   ########.fr       */
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
