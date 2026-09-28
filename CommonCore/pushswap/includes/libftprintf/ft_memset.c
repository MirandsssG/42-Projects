/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 03:14:12 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/01/14 13:47:16 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c_char;
	char			*s_str;

	i = 0;
	c_char = (unsigned char)c;
	s_str = (char *)s;
	while (i < n)
	{
		s_str[i] = c_char;
		i++;
	}
	return (s);
}
