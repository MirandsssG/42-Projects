/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:46:40 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/22 12:17:57 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_path_valid(t_data *data)
{
	int		px;
	int		py;
	char	**map_copy;
	int		result;
	int		i;

	px = 0;
	py = 0;
	find_player(data, &px, &py);
	map_copy = copy_map(data->map, data->rows);
	if (!map_copy)
		return (0);
	floodfill(map_copy, px, py);
	result = is_reachable(map_copy);
	i = 0;
	while (i < data->rows)
		free(map_copy[i++]);
	free(map_copy);
	return (result);
}
