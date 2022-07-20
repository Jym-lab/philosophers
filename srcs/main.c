/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:25:58 by yjoo              #+#    #+#             */
/*   Updated: 2022/07/20 16:01:58 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	err_msg(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	main(int ac, char *av[])
{
	t_manager	manager;
	t_philo		*philos;
	t_fork		*fork;

	if (ac > 4)
	{
		argv_init(ac, av, &manager);
		philos = malloc(manager.number_of_philosophers * sizeof(t_philo));
		fork = malloc(manager.number_of_philosophers * sizeof(t_fork));
		if (!philos || !fork)
			err_msg("malloc error");
		memset(philos, 0, manager.number_of_philosophers * sizeof(t_philo));
		memset(philos, 0, manager.number_of_philosophers * sizeof(t_fork));
		free(philos);
		free(fork);
	}
	else
		err_msg("Usage: ./philo [number_of_philosopher] [time_to_die] [time_to_eat] \
[time_to_sleep] ([number_of_times_each_philosopher_must_eat])");
	return (0);
}
