/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:05:49 by mirandsssg        #+#    #+#             */
/*   Updated: 2026/03/03 07:09:51 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
}	t_philo;

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				dead;
	long long		start_time;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_mutex;
	t_philo			*philos;
}	t_data;

// Helpers

int			ft_atoi(const char *str);

int			is_valid_arg(char *str);

long long	get_time_ms(void);

void		ft_usleep(long time_in_ms);

// Initialization

int			init_data(t_data *data);

// Cleanup

void		cleanup_data(t_data *data);

// Execute

int			execute(t_data *data);

void		*philo_routine(void *arg);

int			start_philo(t_data *data);

void		*monitor_routine(void *arg);

int			handle_one(t_data *data);

// Actions

void		print_status(t_philo *philo, char *status);

void		take_forks(t_philo *philo);

void		eat(t_philo *philo);

void		put_forks(t_philo *philo);

void		sleep_and_think(t_philo *philo);

// Parsing

int			validate_args(int ac, char **av);

void		parse_args(int ac, char **av, t_data *data);

#endif