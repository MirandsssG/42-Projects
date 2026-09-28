/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:51:38 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/23 11:22:49 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(char **map, int rows)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	while (i < rows)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}
