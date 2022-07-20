/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:55:31 by yjoo              #+#    #+#             */
/*   Updated: 2022/07/20 15:50:19 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_manager
{
	size_t	number_of_philosophers;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	size_t	number_of_times_each_philosopher_must_eat;
}		t_manager;

typedef struct s_philo
{
	pthread_t	tid;
	size_t		philo_id;
	size_t		eat_cnt;
	t_fork		fork[2];
}		t_philo;

typedef struct s_fork
{
	pthread_mutex_t	m_fork;
	int				state;
}		t_fork;

void	argv_init(int ac, char *av[], t_manager *manager);
void	err_msg(char *msg);

#endif
