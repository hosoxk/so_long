/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:27:20 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/06 00:21:36 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width
		|| new_y < 0 || new_y >= game->map.height)
		return (false);
	if (game->map.data[new_y][new_x] == '1')
		return (false);
	return (true);
}

static int	close_window(t_game *game)
{
	ft_printf("Closing window\n");
	free_mlx(game);
	exit(0);
}

static void	handle_exit(t_game *game, int prev_x, int prev_y)
{
	if (game->player.collected_collectibles == game->map.total_collectibles)
		close_window(game);
	else
		draw_tile(game, prev_x, prev_y, 'E');
}

static void	handle_collectible(t_game *game, int new_x, int new_y)
{
	game->player.collected_collectibles++;
	game->map.data[new_y][new_x] = '0';
}

static void	update_player(t_game *game, int new_x, int new_y)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player.position.x;
	prev_y = game->player.position.y;
	if (game->map.data[new_y][new_x] == 'C')
		handle_collectible(game, new_x, new_y);
	if (game->map.data[new_y][new_x] == 'E')
		handle_exit(game, prev_x, prev_y);
	draw_tile(game, prev_x, prev_y, '0');
	game->map.data[prev_y][prev_x] = '0';
	game->map.data[new_y][new_x] = 'P';
	game->player.position.x = new_x;
	game->player.position.y = new_y;
	draw_tile(game, new_x, new_y, 'P');
}

static int	key_press(int keycode, t_game *game)
{
	int		new_x;
	int		new_y;

	new_x = game->player.position.x;
	new_y = game->player.position.y;
	if (keycode == ESC_KEY || keycode == Q_KEY)
		close_window(game);
	if (keycode == UP_ARROW || keycode == W_KEY)
		new_y -= 1;
	if (keycode == DOWN_ARROW || keycode == S_KEY)
		new_y += 1;
	if (keycode == LEFT_ARROW || keycode == A_KEY)
		new_x -= 1;
	if (keycode == RIGHT_ARROW || keycode == D_KEY)
		new_x += 1;
	if (is_valid_move(game, new_x, new_y))
		update_player(game, new_x, new_y);
	return (0);
}

void	set_up_hooks(t_game *game)
{
	mlx_key_hook(game->window, key_press, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}
