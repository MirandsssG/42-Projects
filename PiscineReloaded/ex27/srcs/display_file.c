/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:13:10 by dluis-ma          #+#    #+#             */
/*   Updated: 2024/10/25 16:14:53 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	display(char *f_name)
{
	int		file;
	char	character;

	file = open(f_name, O_RDONLY);
	if (file < 0)
		return (0);
	while (read(file, &character, 1) > 0)
		write(1, &character, 1);
	close(file);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		write(1, "File name missing.\n", 19);
	else if (ac > 2)
		write(1, "Too many arguments.\n", 20);
	else
	{
		if (display(av[1]) == 0)
			write(1, "Cannot read file.\n", 18);
	}
	return (0);
}
