/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:10:21 by dluis-ma          #+#    #+#             */
/*   Updated: 2024/10/25 15:49:14 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	if (length > 0)
	{
		f(*tab);
		ft_foreach(tab + 1, length - 1, f);
	}
}
/*
void	ft_putnbr(int n)
{
	printf("%d\n", n);
}

int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5};

	ft_foreach(tab, 5, &ft_putnbr);
	return (0);
}
*/