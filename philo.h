/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:26:55 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/20 13:12:09 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_times_each_philosopher_must_eat;
	long			time;
	int				number_of_philo;
	long			count_die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t *checkdeath;
}	t_philo;

typedef struct s_data
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	long	time;
}	t_data;

int		parsing(char **av);
int		ft_isdigit(char	*nbr);
int		check_if_valid_digit(char	*str);
int		ft_atoi(char *str);
int		full_value(char **av, int ac);
int		philosopher(t_data *data);
void	eat(t_philo *philo);
void	sleeep(t_philo *philo);
void	think(t_philo	*philo);
long	my_get_time(void);
int		die(t_philo	*philo);
void	handler_6_arg(pthread_mutex_t *temp, t_philo *philo);
void	*find_your_self(void *arg);
void	free_forks(t_philo *philo);
int		temp_create_philo(pthread_t *philosophers,
			t_philo *philo, t_data *data);
#endif
