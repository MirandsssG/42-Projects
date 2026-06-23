/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 02:35:24 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/26 10:47:17 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

int	line_count(const char *filename)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(filename, O_RDONLY);
	count = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	read_map_into_data(char *map, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		data->map[i++] = line;
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
	return (0);
}

int	initialize_vars(char *map, t_data *data)
{
	data->rows = line_count(map);
	if (data->rows <= 0)
	{
		ft_printf("Failed to read lines or empty file\n");
		return (1);
	}
	data->map = malloc(sizeof(char *) * (data->rows + 1));
	if (!data->map)
	{
		perror("malloc");
		return (1);
	}
	if (read_map_into_data(map, data))
	{
		free(data->map);
		return (1);
	}
	data->columns = str_len_no_nl(data->map[0]);
	if (!parse_map1(data->map, map, *data))
	{
		ft_printf("Invalid map\n");
		free_map(data);
		return (1);
	}
	return (0);
}
