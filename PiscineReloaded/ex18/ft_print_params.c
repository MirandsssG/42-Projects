/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:32:27 by dluis-ma          #+#    #+#             */
/*   Updated: 2024/10/25 15:38:42 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	main(int ac, char **av)
{
	int	i;
	int	count;

	count = 1;
	if (ac > 1)
	{
		while (count < ac)
		{
			i = 0;
			while (av[count][i] != '\0')
			{
				ft_putchar(av[count][i]);
				i++;
			}
			ft_putchar('\n');
			count++;
		}
	}
	return (0);
}
