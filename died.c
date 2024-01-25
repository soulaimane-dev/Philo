/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:54:02 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/25 16:06:32 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_died(t_philo *philo)
{
	int	i;
	int	size;

	size = philo->nbr_of_philo;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			pthread_mutex_lock(philo->checkdeath);
			if (philo[i].time_to_die <= (my_get_time() - philo[i].count_die))
			{
				pthread_mutex_lock(philo->died);
				*philo->die = 0;
				pthread_mutex_unlock(philo->died);
				pthread_mutex_lock(philo->msg);
				usleep(1000);
				printf("%ld %d is die\n", (my_get_time() - philo->time), philo->id);
				return (1);
			}
			pthread_mutex_unlock(philo->checkdeath);
			i++;
		}
	}
	return (0);
}
