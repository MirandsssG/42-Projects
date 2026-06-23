/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:43:35 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/06/16 15:22:23 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/libftprintf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define END_TRANSMISSION '\0'

volatile sig_atomic_t	g_ack_received = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("Error sending SIGUSR2");
				exit(1);
			}
		}
		else if (kill(pid, SIGUSR1) == -1)
		{
			perror("Error sending SIGUSR1");
			exit(1);
		}
		while (!g_ack_received)
			usleep(50);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;
	char				*msg;
	size_t				i;

	if (argc != 3)
		return (write(2, "Usage: ./client <PID> <message>\n", 33), 1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (write(2, "Invalid PID\n", 12), 1);
	msg = argv[2];
	sa.sa_handler = &handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (1)
	{
		send_char(server_pid, msg[i]);
		if (!msg[i++])
			break ;
	}
	return (0);
}
