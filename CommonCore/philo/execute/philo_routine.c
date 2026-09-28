/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:27:36 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/03 07:58:07 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(3000);
	while (1)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->dead_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->dead_mutex);
		take_forks(philo);
		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_meal_time = get_time_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_mutex);
		eat(philo);
		put_forks(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}
