/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:34:05 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/05 23:16:28 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error:\ncorrect usage: %s <map>\n", argv[0]), 1);
	init_game(&game, argv[1]);
	if (!is_map_valid(&game.map))
		return (ft_freearr(game.map.data), 1);
	init_mlx(&game);
	init_images(&game);
	draw_map(&game);
	set_up_hooks(&game);
	ft_printf("Player's pos; x = %d, y = %d", game.player.position.x, game.player.position.y);
	ft_printf("Entering mlx_loop\n");
	mlx_loop(game.mlx);
	return (0);
}
