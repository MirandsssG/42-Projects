/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:54:47 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/27 16:00:13 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_images(t_data *data)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", &w, &h);
	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/floor.xpm", &w, &h);
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player.xpm", &w, &h);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", &w, &h);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/collectible.xpm", &w, &h);
	if (!data->img_wall || !data->img_floor || !data->img_player
		|| !data->img_exit || !data->img_collectible)
	{
		ft_printf("Failed to load textures\n");
		ft_exit(data);
		return (0);
	}
	return (1);
}
