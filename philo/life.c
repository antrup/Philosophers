/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:50:33 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/02 18:48:28 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_param *data)
{
	pthread_mutex_lock(data->fork1);
	print_msg(data, "has taken a fork\n");
	if (data->fork2 == NULL)
	{	
		usleep(data->time_to_die * 1000);
		return ;
	}
	pthread_mutex_lock(data->fork2);
	print_msg(data, "has taken a fork\n");
	pthread_mutex_lock(data->lunch);
	data->last_eat = timeformat();
	pthread_mutex_unlock(data->lunch);
	print_msg(data, "is eating\n");
	return ;
}

void	precise_sleep(long	zzz)
{
	long	now;

	now = timeformat();
	while (timeformat() - now < zzz)
		usleep(50);
}

void	*life(void *params)
{
	t_param	*data;

	data = (t_param *)params;
	while (data->max_eat != 0)
	{
		eat(data);
		precise_sleep(data->time_to_eat);
		pthread_mutex_unlock(data->fork1);
		if (data->fork2)
			pthread_mutex_unlock(data->fork2);
		if (data->smb_died[0])
			return (NULL);
		print_msg(data, "is sleeping\n");
		precise_sleep(data->time_to_sleep);
		print_msg(data, "is thinking\n");
		(data->max_eat)--;
	}
	return (NULL);
}

void	*check(void *params)
{
	t_param	*data;
	long	last_e;

	data = (t_param *)params;
	while (!(data->smb_died[0]) && data->max_eat != 0)
	{
		pthread_mutex_lock(data->lunch);
		last_e = data->last_eat;
		pthread_mutex_unlock(data->lunch);
		if (timeformat() >= data->time_to_die + last_e)
		{
			pthread_mutex_lock(data->printer);
			if (!(data->smb_died[0]))
			{	
				data->smb_died[0] = 1;
				printf("%lu %d died\n", timeformat() - data->start_time,
					data->id);
			}
			pthread_mutex_unlock(data->printer);
		}
	}
	return (NULL);
}
