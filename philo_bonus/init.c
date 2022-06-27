/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:24:12 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/04 17:19:43 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_param(t_param *params, char **argv, int id)
{
	params->id = id;
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
}

int	init_param2(t_param *params, t_bag bag, char **argv)
{
	char	*semname;

	params->fork = bag.sem[0];
	params->printer = bag.sem[1];
	params->nb_eat = 0;
	if (argv[5])
		params->max_eat = ft_atoi(argv[5]);
	else
		params->max_eat = -1;
	semname = ft_itoa(params->id);
	if (!semname)
		return (1);
	sem_unlink(semname);
	params->lunch = sem_open(semname, O_CREAT, 0777, 1);
	free(semname);
	params->start_time = bag.start_time;
	params->last_eat = params->start_time;
	return (0);
}
