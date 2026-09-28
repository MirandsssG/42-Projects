/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:07:24 by dluis-ma          #+#    #+#             */
/*   Updated: 2025/05/27 11:42:55 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_surrounded(char **map, t_data data)
{
	int		i;
	size_t	len;

	i = 1;
	if (!map || !map[0])
		return (0);
	len = str_len_no_nl(map[0]);
	if (!top_or_bottom_row(map[0]))
		return (0);
	while (i < data.rows - 1)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	if (!top_or_bottom_row(map[data.rows - 1]))
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

int	is_bigger_than_window(t_data data)
{
	if (data.columns > 30 || data.rows > 16)
		return (0);
	return (1);
}
