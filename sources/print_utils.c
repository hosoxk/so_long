/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:08:34 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/07 17:15:40 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map_data(char **data)
{
	int	i;

	i = 0;
	ft_printf("Contents of map->data:\n");
	while (data[i] != NULL)
	{
		ft_printf("%s\n", data[i]);
		i++;
	}
}
