/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:17:02 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/20 12:47:12 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d has taken a fork\n",
		(my_get_time() - philo->time), philo->id);
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n",
		(my_get_time() - philo->time), philo->id);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(philo->checkdeath);
	philo->count_die = my_get_time();
	pthread_mutex_unlock(philo->checkdeath);
	printf("%ld %d is eating\n", (my_get_time() - philo->time), philo->id);
	usleep(philo->time_to_eat);
	put_fork(philo);
}

void	think(t_philo	*philo)
{
	printf("%ld %d is thinking\n", (my_get_time() - philo->time), philo->id);
}

void	sleeep(t_philo *philo)
{
	printf("%ld %d is sleeping\n", (my_get_time() - philo->time), philo->id);
	usleep(philo->time_to_sleep);
}
