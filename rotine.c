/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:23:59 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/25 11:20:06 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	put_mssg("has taken a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	put_mssg("has taken a fork", philo);
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
	put_mssg("is eating", philo);
	my_usleep(philo->time_to_eat);
	put_fork(philo);
}

void	think(t_philo	*philo)
{
	put_mssg("is thinking", philo);
}

void	sleeep(t_philo *philo)
{
	put_mssg("is sleeping", philo);
	my_usleep(philo->time_to_sleep);
}
