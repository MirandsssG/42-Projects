/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:29:11 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/23 11:15:29 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ber_extension(const char *filename)
{
	const char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".ber") != 0)
		return (0);
	return (1);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P'
		|| c == 'E' || c == 'C' || c == '\n');
}

void	count_map_elements(char **map, int *p, int *e, int *c)
{
	int	i;
	int	j;

	*p = 0;
	*e = 0;
	*c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}

int	check_char(char **map)
{
	int	p;
	int	e;
	int	c;

	count_map_elements(map, &p, &e, &c);
	return (p == 1 && e == 1 && c >= 1);
}

int	top_or_bottom_row(char *row)
{
	int	i;

	i = 0;
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
