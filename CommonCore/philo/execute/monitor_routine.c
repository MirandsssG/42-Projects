/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:43:15 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/02/26 22:40:50 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_philo_dead(t_philo *philo, t_data *data)
{
	long long	time_diff;

	pthread_mutex_lock(&philo->meal_mutex);
	time_diff = get_time_ms() - philo->last_meal_time;
	if (time_diff > data->time_to_die)
	{
		pthread_mutex_lock(&data->dead_mutex);
		data->dead = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		print_status(philo, "died");
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

static int	check_all_philos_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (check_philo_dead(&data->philos[i], data))
			return (1);
		i++;
	}
	return (0);
}

static int	check_all_full(t_data *data)
{
	int			i;
	int			all_full;

	i = 0;
	all_full = 1;
	while (i < data->number_of_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		if (data->must_eat_count > 0
			&& data->philos[i].meals_eaten < data->must_eat_count)
			all_full = 0;
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		i++;
	}
	return (all_full);
}

static int	handle_all_full(t_data *data)
{
	int	all_full;

	if (data->must_eat_count <= 0)
		return (0);
	all_full = check_all_full(data);
	if (all_full)
	{
		pthread_mutex_lock(&data->dead_mutex);
		data->dead = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		dead_flag;

	data = (t_data *)arg;
	while (1)
	{
		if (check_all_philos_dead(data))
			return (NULL);
		if (handle_all_full(data))
			return (NULL);
		pthread_mutex_lock(&data->dead_mutex);
		dead_flag = data->dead;
		pthread_mutex_unlock(&data->dead_mutex);
		if (dead_flag)
			break ;
		usleep(200);
	}
	return (NULL);
}
