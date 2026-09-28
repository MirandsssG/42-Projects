/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:57:54 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/04 17:39:54 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (validate_args(ac, av))
		return (1);
	parse_args(ac, av, &data);
	if (data.number_of_philos == 1)
	{
		handle_one(&data);
		return (0);
	}
	if (init_data(&data))
		return (cleanup_data(&data), 1);
	if (execute(&data))
		return (cleanup_data(&data), 1);
	cleanup_data(&data);
	printf("Program finished Successfully\n");
	return (0);
}
