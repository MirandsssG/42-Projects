/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:51:42 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/02/11 15:06:00 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	execute(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = get_time_ms();
	if (start_philo(data))
		return (1);
	if (pthread_create(&monitor_thread, NULL, monitor_routine, data) != 0)
		return (printf("Error: failed to create monitor thread\n"), 1);
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	return (0);
}
