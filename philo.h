/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:02:10 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/25 12:05:20 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data
{
	int		nbr_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_of_times_eat;
	long	time;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				nbr_of_philo;
	long			time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_of_times_eat;
	long			count_die;
	int				*die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t *checkdeath;
	pthread_mutex_t *msg;
	pthread_mutex_t *died;
}	t_philo;

typedef struct s_allocate
{
	t_philo			*philo;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*checkdeath;
	pthread_mutex_t	*died;
} t_allocate;


int		parsing(char **av);
int		full_value(char **av, int ac);
int		ft_atoi(char *str);
long	my_get_time(void);
int		started_life(t_data *data);
void	put_mssg(char *msg, t_philo *philo);
void	my_usleep(unsigned int time);
void	sleeep(t_philo *philo);
void	think(t_philo	*philo);
void	eat(t_philo *philo);
int	check_if_died(t_philo *philo);


#endif
