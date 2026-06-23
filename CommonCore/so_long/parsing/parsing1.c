/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:08:31 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/28 13:33:16 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	str_len_no_nl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

int	validate_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_rectangular(char **map, t_data data)
{
	int		i;
	size_t	len;

	i = 0;
	if (!map || !map[0])
		return (0);
	len = str_len_no_nl(map[0]);
	while (map[i] && i < data.rows)
	{
		if (str_len_no_nl(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	parse_map1(char **map, const char *filename, t_data data)
{
	if (!validate_char(map))
		return (0);
	if (!ber_extension(filename))
		return (0);
	if (!check_char(map))
		return (0);
	if (!parse_map2(map, data))
		return (0);
	if (!is_path_valid(&data))
		return (0);
	return (1);
}

int	parse_map2(char **map, t_data data)
{
	if (!is_rectangular(map, data))
		return (0);
	if (!is_surrounded(map, data))
		return (0);
	if (!is_bigger_than_window(data))
		return (0);
	return (1);
}
