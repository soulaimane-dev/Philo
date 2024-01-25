/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:06:10 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/24 17:24:00 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char	*nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9') && (nbr[i] != '+'))
			return (1);
		i++;
	}
	return (0);
}

int	parsing(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 1)
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
	{
		write(2, "invalid input\n", 18);
		return (1);
	}
	data.nbr_of_philo = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	data.time = my_get_time();
	if (ac == 6)
	{
		if (ft_atoi(av[5]) <= 0)
			return (1);
		else
			data.nbr_of_times_eat = ft_atoi(av[5]);
	}
	else
		data.nbr_of_times_eat = -1;
	if (started_life(&data) == 1)
		return (1);
	return (0);
}
