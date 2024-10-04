/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:34:05 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/04 18:55:36 by yde-rudd         ###   ########.fr       */
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
	ft_freearr(game.map.data);
	free_mlx(&game);
}
