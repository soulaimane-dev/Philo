/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   started_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:24:04 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/25 16:21:40 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*find_your_self(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(100);
	while (1)
	{
		eat(philo);
		think(philo);
		sleeep(philo);
	}
	return (NULL);
}

int	create_philos(t_philo *philo, pthread_t *philos)
{
	int	i;

	i = 0;
	while (i < philo->nbr_of_philo)
	{
		if (pthread_create(&philos[i], NULL, &find_your_self, (void *)&philo[i]) != 0)
			return (1);
		i++;
	}
	check_if_died(philo);
	if (*philo->die != 1)
	{
		i = 0;
		while (i < philo->nbr_of_philo)
		{
			pthread_detach(philos[i]);
			i++;
		}
	}
	return (1);
}

int	gives_info(t_allocate *al, t_data *data)
{
	int	i;
	int	die;

	i = 0;
	die = 1;
	while (i < data->nbr_of_philo)
	{
		al->philo[i].id = i + 1;
		al->philo[i].nbr_of_philo = data->nbr_of_philo;
		al->philo[i].time_to_die = data->time_to_die;
		al->philo[i].time_to_eat = data->time_to_eat;
		al->philo[i].time_to_sleep = data->time_to_sleep;
		al->philo[i].nbr_of_times_eat = data->nbr_of_times_eat;
		al->philo[i].right_fork  =	&al->forks[i];
		al->philo[i].time = data->time;
		al->philo[i].count_die = data->time;
		al->philo[i].msg = al->msg;
		al->philo[i].die = &die;
		al->philo[i].died = al->died;
		al->philo[i].checkdeath = al->checkdeath;
		if (i == data->nbr_of_philo - 1)
			al->philo[i].left_fork = &al->forks[0];
		else
			al->philo[i].left_fork = &al->forks[i + 1];
		i++;
	}
	create_philos(al->philo, al->philos);
	return (1);
}


int	started_life(t_data *data)
{
	t_allocate al;

	al.philos = malloc(sizeof(pthread_t) * data->nbr_of_philo);
	if (al.philos == NULL)
		return (1);
	al.philo = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (al.philo == NULL)
		return (free(al.philos), 1);
	al.forks = malloc(data->nbr_of_philo * sizeof(pthread_mutex_t));
	if (al.forks == NULL)
		return (free(al.philos), free(al.philo), 1);
	al.msg = malloc(sizeof(pthread_mutex_t) * 1);
	if (al.msg == NULL)
		return (free(al.philos), free(al.philo),free(al.forks), 1);
	al.checkdeath = malloc(sizeof(pthread_mutex_t));
	if (al.checkdeath == NULL)
		return (free(al.philos), free(al.philo),free(al.forks), free(al.msg), 1);
	al.died = malloc(sizeof(pthread_mutex_t));
	if (al.died == NULL)
		return (free(al.philos),free(al.checkdeath) , free(al.philo),free(al.forks), free(al.msg), 1);
	pthread_mutex_init(al.checkdeath, NULL);
	pthread_mutex_init(al.msg, NULL);
	pthread_mutex_init(al.died, NULL);
	int	i = 0;
	while (i < data->nbr_of_philo)
	{
		pthread_mutex_init(&al.forks[i], NULL);
		i++;
	}
	if (gives_info(&al, data) == 1)
	{
		return (free(al.philos), free(al.philo),free(al.forks), free(al.msg), free(al.checkdeath), free(al.died), 1);
	}
	return (0);
}
