/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:50:33 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/04 15:58:43 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_param *data)
{
	sem_wait(data->fork);
	print_msg(data, "has taken a fork\n");
	sem_wait(data->fork);
	print_msg(data, "has taken a fork\n");
	sem_wait(data->lunch);
	data->last_eat = timeformat();
	sem_post(data->lunch);
	print_msg(data, "is eating\n");
	return ;
}

void	precise_sleep(long	zzz)
{
	long	now;

	now = timeformat();
	while (timeformat() - now < zzz)
		usleep(100);
}

void	*life(void *params)
{
	t_param	*data;

	data = (t_param *)params;
	while (data->max_eat != 0)
	{
		eat(data);
		precise_sleep(data->time_to_eat);
		sem_post(data->fork);
		sem_post(data->fork);
		print_msg(data, "is sleeping\n");
		precise_sleep(data->time_to_sleep);
		print_msg(data, "is thinking\n");
		(data->max_eat)--;
	}
	exit(0);
	return (NULL);
}

void	*check(void *params)
{
	t_param	*data;
	long	last_e;

	data = (t_param *)params;
	while (data->max_eat != 0)
	{
		sem_wait(data->lunch);
		last_e = data->last_eat;
		sem_post(data->lunch);
		if (timeformat() >= data->time_to_die + last_e)
		{
			sem_wait(data->printer);
			printf("%lu %d died\n", timeformat() - data->start_time,
				data->id);
			exit(1);
		}
	}
	return (NULL);
}
