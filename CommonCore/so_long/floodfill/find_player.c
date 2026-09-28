/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:48:04 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/22 12:48:47 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(t_data *data, int *px, int *py)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
