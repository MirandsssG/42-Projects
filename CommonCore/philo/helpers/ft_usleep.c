/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:37:49 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/02/26 22:43:02 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(long time_in_ms)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < time_in_ms)
		usleep(100);
}
