/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:38:13 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/02/27 00:36:35 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	cleanup_data(t_data *data)
{
	int	i;

	if (data->philos)
	{
		i = 0;
		while (i < data->number_of_philos)
		{
			pthread_mutex_destroy(&data->philos[i].meal_mutex);
			i++;
		}
		free(data->philos);
	}
	if (data->forks)
	{
		i = 0;
		while (i < data->number_of_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	pthread_mutex_destroy(&data->lock_print);
	pthread_mutex_destroy(&data->dead_mutex);
}
