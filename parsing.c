/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:51:06 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/19 19:11:25 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 1)
			return (1);
		if (check_if_valid_digit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	full_value(char **av, int ac)
{
	t_data	data;

	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (1);
	data.number_of_philosophers = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]) * 1000;
	data.time_to_eat = ft_atoi(av[3]) * 1000;
	data.time_to_sleep = ft_atoi(av[4]) * 1000;
	data.time = my_get_time();
	if (ac == 6)
	{
		if (ft_atoi(av[5]) <= 0)
			return (1);
		else
			data.number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	}
	else
		data.number_of_times_each_philosopher_must_eat = -1;
	if (philosopher(&data) == 1)
		return (1);
	return (0);
}
