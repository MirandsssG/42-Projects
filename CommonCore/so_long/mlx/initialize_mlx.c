/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:35:38 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/30 23:43:15 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	initialize_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_printf("Failed to initialize MiniLibX\n"), 0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->columns * 64,
			data->rows * 64, "so_long");
	if (!data->win_ptr)
		return (ft_printf("Failed to create window\n"), 0);
	if (!load_images(data))
		return (ft_printf("Failed to load textures\n"), 0);
	draw_map(data);
	data->steps = 0;
	data->curr_pos = '0';
	data->next_pos = '0';
	mlx_key_hook(data->win_ptr, key_handler, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
