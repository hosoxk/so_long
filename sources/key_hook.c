/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:32:31 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/07 17:07:16 by yde-rudd         ###   ########.fr       */
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

int	close_window(t_game *game)
{
	free_mlx(game);
	exit(0);
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
	if (is_valid_move(game, new_x, new_y) && (keycode == UP_ARROW
			|| keycode == W_KEY || keycode == DOWN_ARROW || keycode == S_KEY
			|| keycode == LEFT_ARROW || keycode == A_KEY
			|| keycode == RIGHT_ARROW || keycode == D_KEY))
		update_player(game, new_x, new_y);
	return (0);
}

void	set_up_hooks(t_game *game)
{
	mlx_key_hook(game->window, key_press, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}
