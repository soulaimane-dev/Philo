/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:01:01 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/25 14:34:04 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f()
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	// atexit(f);
	if (ac != 5 && ac != 6)
	{
		write(2, "invalid input\n", 15);
		return (1);
	}
	if (parsing(av) == 1)
	{
		write(2, "invalid input\n", 15);
		return (1);
	}
	if (full_value(av, ac) == 1)
		return (0);
	return (0);
}
