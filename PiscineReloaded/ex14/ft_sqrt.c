/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:01:47 by dluis-ma          #+#    #+#             */
/*   Updated: 2024/10/22 14:39:49 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i < (nb / 2))
	{
		if (i * i == nb)
			return (i);
		else
			i++;
	}
	return (0);
}
/*
int	main(void)
{
	int	nb;

	nb = 0;
	printf("%d", ft_sqrt(nb));
	return (0);
}
*/