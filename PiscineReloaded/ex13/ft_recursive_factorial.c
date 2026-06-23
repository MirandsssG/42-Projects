/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:58:23 by dluis-ma          #+#    #+#             */
/*   Updated: 2024/10/25 16:33:59 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	overflow;

	if (nb == 0)
	{
		return (1);
	}
	else if (nb < 0)
	{
		return (0);
	}
	overflow = nb * ft_recursive_factorial(nb - 1);
	if (overflow < 0)
		return (0);
	return (overflow);
}
/*
int	main(void)
{
	int	nb;

	nb = 20;
	printf("%d", ft_recursive_factorial(nb));
	return (0);
}
*/