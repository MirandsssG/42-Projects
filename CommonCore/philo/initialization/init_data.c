/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:03:22 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/02/11 14:30:18 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	if (!data->forks)
		return (printf("Error: malloc (forks)\n"), 1);
	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("Error: forks mutex init\n");
			cleanup_data(data);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	init_philo(t_philo *philo, t_data *data, int id)
{
	philo->id = id + 1;
	philo->meals_eaten = 0;
	philo->last_meal_time = data->start_time;
	philo->left_fork = &data->forks[id];
	philo->right_fork = &data->forks[(id + 1) % data->number_of_philos];
	philo->data = data;
	if (pthread_mutex_init(&philo->meal_mutex, NULL) != 0)
	{
		printf("Error: meal mutex init\n");
		cleanup_data(data);
		return (1);
	}
	return (0);
}

static int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->number_of_philos);
	if (!data->philos)
	{
		printf("Error: malloc (philos)\n");
		cleanup_data(data);
		return (1);
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		if (init_philo(&data->philos[i], data, i))
			return (1);
		i++;
	}
	return (0);
}

static int	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->lock_print, NULL) != 0)
	{
		printf("Error: lock print mutex init\n");
		cleanup_data(data);
		return (1);
	}
	if (pthread_mutex_init(&data->dead_mutex, NULL) != 0)
	{
		printf("Error: dead mutex init\n");
		cleanup_data(data);
		return (1);
	}
	return (0);
}

int	init_data(t_data *data)
{
	data->dead = 0;
	data->start_time = get_time_ms();
	if (init_forks(data))
		return (1);
	if (init_mutexes(data))
		return (1);
	if (init_philos(data))
		return (1);
	return (0);
}
