/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:53:59 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/01/14 13:47:12 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*pointer;

	pointer = (void *)malloc(nelem * elsize);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, nelem * elsize);
	return (pointer);
}
