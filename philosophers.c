/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:43:47 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/20 13:17:34 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(t_philo *philo)
{
	int	i;
	int	size;

	i = 0;
	size = philo[i].number_of_philo;
	while (i < size)
	{
		free(philo->right_fork);
		i++;
	}
}

int	make_forks(int size, t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		philo[i].right_fork = &forks[i];
		if (i == size - 1)
			philo[i].left_fork = &forks[0];
		else
			philo[i].left_fork = &forks[i + 1];
		i++;
	}
	return (0);
}

void	*find_your_self(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	temp;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(100);
	if (philo->number_of_times_each_philosopher_must_eat == -1)
	{
		while (1)
		{
			eat(philo);
			sleeep(philo);
			think(philo);
		}
	}
	else
	{
		pthread_mutex_init(&temp, NULL);
		handler_6_arg(&temp, philo);
		return (NULL);
	}
}

int	create_philosophers(pthread_t *philosophers, t_philo *philo, t_data *data)
{
	int	i;

	if (temp_create_philo(philosophers, philo, data) == 1)
		return (1);
	i = 0;
	if (data->number_of_times_each_philosopher_must_eat == -1
		|| data->number_of_philosophers == 1)
		if (die(philo) == 1)
			return (1);
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philosophers[i], NULL))
			return (1);
		i++;
	}
	return (0);
}


int	philosopher(t_data *data)
{
	t_philo			*philo;
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;

	philosophers = malloc(sizeof(pthread_t) * data->number_of_philosophers);
	if (philosophers == NULL)
		return (1);
	philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (philo == NULL)
		return (free(philosophers), 1);
	forks = malloc(data->number_of_philosophers * sizeof(pthread_mutex_t));
	if (forks == NULL)
		return (free(philosophers), free(philo), 1);
	if (make_forks(data->number_of_philosophers, philo, forks) == 1)
	{
		return (free(forks), free(philo), free(philosophers), 1);
	}
	if (create_philosophers(philosophers, philo, data) == 1)
	{
		return (free(philo->checkdeath), free(forks), free(philosophers), free(philo), 1);
	}
	return (0);
}
