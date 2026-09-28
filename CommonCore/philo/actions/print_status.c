/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:51:09 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/02/11 14:20:06 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	print_status(t_philo *philo, char *status)
{
	long long	time;
	int			is_dead;

	pthread_mutex_lock(&philo->data->lock_print);
	pthread_mutex_lock(&philo->data->dead_mutex);
	is_dead = philo->data->dead;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	if (is_dead && ft_strcmp(status, "died") != 0)
	{
		pthread_mutex_unlock(&philo->data->lock_print);
		return ;
	}
	time = get_time_ms() - philo->data->start_time;
	printf("%lld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->data->lock_print);
}
