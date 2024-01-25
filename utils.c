/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:04:14 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/25 16:03:02 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	my_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	my_usleep(unsigned int time)
{
	long	start;

	start = my_get_time();
	while (my_get_time() - start < time)
		usleep(100);
}

void	put_mssg(char *msg, t_philo *philo)
{
	pthread_mutex_lock(philo->died);
	pthread_mutex_lock(philo->msg);
	if(*philo->die == 0)
		return;
	printf("%ld %d %s\n", (my_get_time() - philo->time), philo->id, msg);
	pthread_mutex_unlock(philo->died);
	pthread_mutex_unlock(philo->msg);
}

int	ft_atoi(char *str)
{
	char	*s;
	int		sign;
	int		nbr;

	sign = 1;
	nbr = 0;
	s = (char *) str;
	while (*s == ' ')
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	return (nbr * sign);
}
