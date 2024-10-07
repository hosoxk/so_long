/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:27:20 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/07 16:31:33 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handle_collectible(t_game *game)
{
	game->player.collected_collectibles++;
	ft_printf("Collected: %d/%d\n", game->player.collected_collectibles,
		game->map.total_collectibles);
}

static void	handle_exit(t_game *game, int prev_x, int prev_y)
{
	if (game->player.collected_collectibles == game->map.total_collectibles)
		close_window(game);
	else
	{
		game->player.on_exit = true;
		draw_tile(game, prev_x, prev_y, '0');
		game->map.data[prev_y][prev_x] = '0';
	}
}

static void	set_data(t_game *game, int new_x, int new_y)
{
	game->map.data[new_y][new_x] = 'P';
	draw_tile(game, new_x, new_y, 'P');
	game->player.position.x = new_x;
	game->player.position.y = new_y;
}

void	update_player(t_game *game, int new_x, int new_y)
{
	int	prev_x;
	int	prev_y;

	game->player.moves++;
	ft_printf("Steps taken: %d\n", game->player.moves);
	prev_x = game->player.position.x;
	prev_y = game->player.position.y;
	if (game->map.data[new_y][new_x] == 'C')
		handle_collectible(game);
	if (game->player.on_exit)
	{
		game->player.on_exit = false;
		game->map.data[prev_y][prev_x] = 'E';
		draw_tile(game, prev_x, prev_y, 'E');
	}
	else
	{
		game->map.data[prev_y][prev_x] = '0';
		draw_tile(game, prev_x, prev_y, '0');
	}
	if (game->map.data[new_y][new_x] == 'E')
		handle_exit(game, prev_x, prev_y);
	set_data(game, new_x, new_y);
}
