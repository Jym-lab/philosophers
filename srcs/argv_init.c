/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:25:55 by yjoo              #+#    #+#             */
/*   Updated: 2022/07/20 15:07:05 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_atoi(const char *nptr)
{
	int	result;
	int	minus;

	result = 0;
	minus = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * minus);
}

void	argv_init(int ac, char *av[], t_manager *m)
{
	m->number_of_philosophers = ft_atoi(av[1]);
	m->time_to_die = ft_atoi(av[2]);
	m->time_to_eat = ft_atoi(av[3]);
	m->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		m->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		m->number_of_times_each_philosopher_must_eat = 0;
	if ((m->time_to_eat | m->time_to_die | m->time_to_sleep) < 0)
		err_msg("Input argument must be positive");
}
