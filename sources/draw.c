/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:43:15 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/05 22:57:56 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_tile(t_game *game, int x, int y, char tile)
{
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, x, y, game->map.data[y][x]);
			x++;
		}
		y++;
	}
}
