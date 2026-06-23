/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluis-ma <dluis-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 07:08:47 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/04 17:18:48 by dluis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	handle_one(t_data *data)
{
	long long	time;

	data->start_time = get_time_ms();
	time = get_time_ms() - data->start_time;
	printf("%lld 1 has taken a fork\n", time);
	usleep(data->time_to_die * 1000);
	time = get_time_ms() - data->start_time;
	printf("%lld 1 died\n", time);
	return (0);
}
