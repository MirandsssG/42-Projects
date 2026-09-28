/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:43:47 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/06/16 15:24:55 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/libftprintf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define END_TRANSMISSION '\0'

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	char_builder = 0;

	(void)context;
	if (sig == SIGUSR2)
		char_builder |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &char_builder, 1);
		if (char_builder == '\0')
			write(1, "\n", 1);
		bit_count = 0;
		char_builder = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
