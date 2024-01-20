/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:11:39 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/20 13:12:59 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die(t_philo	*philo)
{
	int	i;
	int	size;

	size = philo->number_of_philo;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			pthread_mutex_lock(philo->checkdeath);
			if (philo[i].time_to_die / 1000 < my_get_time()
				- philo[i].count_die)
			{
				printf("%ld %d is die\n",
					(my_get_time() - philo->time), philo->id);
				return (1);
			}
			pthread_mutex_unlock(philo->checkdeath);
			i++;
		}
	}
	return (0);
}

void	handler_6_arg(pthread_mutex_t *temp, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_times_each_philosopher_must_eat)
	{
		eat(philo);
		sleeep(philo);
		think(philo);
		pthread_mutex_lock(temp);
		i++;
		pthread_mutex_unlock(temp);
	}
}

int	temp_create_philo(pthread_t *philosophers, t_philo *philo, t_data *data)
{
	int	i;
	pthread_mutex_t *die;

	die = malloc(sizeof(pthread_mutex_t));
	if (die == NULL)
		return (1);
	if (pthread_mutex_init(die, NULL) != 0)
		return (1);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].id = i + 1;
		 philo[i].time_to_die = data->time_to_die;
		philo[i].time_to_eat = data->time_to_eat;
		philo[i].time_to_sleep = data->time_to_sleep;
		philo[i].checkdeath = die;
		philo[i].number_of_times_each_philosopher_must_eat
			= data->number_of_times_each_philosopher_must_eat;
		philo[i].time = data->time;
		philo[i].number_of_philo = data->number_of_philosophers;
		philo[i].count_die = data->time;
		if (pthread_create(&philosophers[i], NULL,
				&find_your_self, (void *)&philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

// philosophers ===>0x7fb6194058a0<=======
// philo ====>0x7fb6194058d0<======
// forks ====>0x7fb619405a90<====
// die ====>0x7fb619405bd0<======
// 0x7fb619405bd0>
// 0x7fb619405a90
// 0x7fb6194058d0
// 0x7fb6194058a0
