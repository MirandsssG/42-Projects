/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:57:52 by dluis-ma          #+#    #+#             */
/*   Updated: 2024/10/25 17:03:11 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	if (nb < 0)
		return (0);
	result = 1;
	i = nb;
	while (i >= 1)
	{
		result *= i;
		if (result < 0 || result > INT_MAX)
			return (0);
		i--;
	}
	return (result);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	int bs = atoi(av[1]);
	printf("%d", ft_iterative_factorial(bs));
	printf("%d", ft_iterative_factorial2(bs));
	return (0);
}
*/