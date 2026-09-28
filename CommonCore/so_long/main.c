/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:42:26 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/23 11:26:57 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf ("Usage: %s <filename>\n", av[0]);
		return (1);
	}
	if (initialize_vars(av[1], &data))
		return (1);
	if (!initialize_mlx(&data))
		return (1);
	return (0);
}
