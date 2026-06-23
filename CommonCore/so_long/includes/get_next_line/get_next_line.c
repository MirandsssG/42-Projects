/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:17:18 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/14 16:46:42 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && BUFFER_SIZE > 0) && (bytes_read > 0 || buff[0]))
	{
		if (!buff[0])
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read <= 0)
				break ;
			buff[bytes_read] = '\0';
		}
		line = ft_strjoin_gnl(line, buff);
		if (!line)
			return (NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

// int main(void)
// {
// 	char *line;

//     int fd = open("map1.ber", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     line = get_next_line(fd);
// 	printf("Line: %s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("Line: %s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("Line: %s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("Line: %s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("Line: %s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("Line: %s", line);
// 	free(line);
//     line = get_next_line(fd);
// 	printf("Line: %s", line);
// 	free(line);

//     close(fd);
//     return (0);
// }
