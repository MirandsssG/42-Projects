/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:43:44 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/23 10:36:06 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_tile(t_data *data, int x, int y, int *collectible_counter)
{
	char	pos;
	void	*img;

	pos = data->map[y][x];
	img = NULL;
	if (pos == '1')
		img = data->img_wall;
	else if (pos == '0')
		img = data->img_floor;
	else if (pos == 'P')
	{
		img = data->img_player;
		data->player_x = x;
		data->player_y = y;
	}
	else if (pos == 'E')
		img = data->img_exit;
	else if (pos == 'C')
	{
		img = data->img_collectible;
		(*collectible_counter)++;
	}
	if (img)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img, x * 64, y * 64);
}

int	draw_map(t_data *data)
{
	int	y;
	int	collectible_counter;
	int	x;

	y = 0;
	collectible_counter = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			draw_tile(data, x, y, &collectible_counter);
			x++;
		}
		y++;
	}
	data->collectible_count = collectible_counter;
	return (1);
}
