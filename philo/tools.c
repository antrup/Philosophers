/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:26:53 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/01 13:51:05 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_param *data, char *msg)
{
	pthread_mutex_lock(data->printer);
	if (data->smb_died[0])
	{
		pthread_mutex_unlock(data->printer);
		return ;
	}
	printf("%lu %d %s", timeformat() - data->start_time, data->id, msg);
	pthread_mutex_unlock(data->printer);
}

long	timeformat(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}
