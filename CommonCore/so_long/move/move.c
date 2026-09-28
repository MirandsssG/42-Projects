/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:43:47 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/27 11:42:24 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	attempt_move(t_data *data, int new_x, int new_y)
{
	char	next_pos;

	next_pos = data->map[new_y][new_x];
	if (next_pos == '1')
		return ;
	if (next_pos == 'C')
		data->collectible_count--;
	if (next_pos == 'E')
	{
		if (data->collectible_count == 0)
		{
			ft_printf("Congratulations, you won in %d steps!\n",
				data->steps + 1);
			ft_exit(data);
		}
		else
			data->next_pos = 'E';
	}
	if (next_pos == 'C' || next_pos == '0')
		data->next_pos = '0';
	move (data, new_x, new_y);
}

void	move(t_data *data, int new_x, int new_y)
{
	if (data->curr_pos == '0')
		data->map[data->player_y][data->player_x] = '0';
	if (data->curr_pos == 'E')
		data->map[data->player_y][data->player_x] = 'E';
	data->map[new_y][new_x] = 'P';
	data->player_x = new_x;
	data->player_y = new_y;
	data->steps++;
	ft_printf("Steps: %d\n", data->steps);
	draw_map(data);
}
