/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:24:12 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/05 19:54:52 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*create_forks(int nb)
{
	pthread_mutex_t		*forks;
	int					i;

	forks = malloc(sizeof(pthread_mutex_t) * nb);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		i++;
	}
	return (forks);
}

t_param	*init_param(char **argv,
	pthread_mutex_t *lunch, int *smb_died)
{
	t_param		*params;
	int			i;

	params = malloc(sizeof(t_param) * ft_atoi(argv[1]));
	if (!params)
		return (NULL);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		params[i].id = i + 1;
		params[i].nb_p = ft_atoi(argv[1]);
		params[i].time_to_die = ft_atoi(argv[2]);
		params[i].time_to_eat = ft_atoi(argv[3]);
		params[i].time_to_sleep = ft_atoi(argv[4]);
		params[i].smb_died = smb_died;
		params[i].start_time = timeformat();
		params[i].lunch = &(lunch[i]);
		i++;
	}
	return (params);
}

void	int_param3(t_param **params, char **argv, pthread_mutex_t *forks)
{
	int		i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		params[0][i].fork1 = &(forks[i]);
		if (ft_atoi(argv[1]) == 1)
			params[0][i].fork2 = NULL;
		else
		{	
			if (i == ft_atoi(argv[1]) - 1)
				params[0][i].fork2 = &(forks[0]);
			else
				params[0][i].fork2 = &(forks[i + 1]);
		}
		i++;
	}
}

int	init_param2(t_param **params, int nb, int argc, char **argv)
{
	int				i;
	pthread_mutex_t	*printer;

	printer = malloc(sizeof(pthread_mutex_t));
	if (!printer)
		return (1);
	pthread_mutex_init(printer, NULL);
	i = 0;
	while (i < nb)
	{
		params[0][i].last_eat = params[0][i].start_time;
		params[0][i].printer = printer;
		params[0][i].nb_eat = 0;
		if (argc == 6)
			params[0][i].max_eat = ft_atoi(argv[5]);
		else
			params[0][i].max_eat = -1;
		i++;
	}
	return (0);
}

pthread_t	*init_thread(int nb, t_param *param)
{
	int			i;
	pthread_t	*philos;

	philos = malloc(sizeof(pthread_t) * nb * 2);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		pthread_create(&(philos[i]), NULL, &life, &(param[i]));
		pthread_create(&(philos[nb + i]), NULL, &check, &(param[i]));
		i = i + 2;
	}
	usleep(500);
	i = 1;
	while (i < nb)
	{
		pthread_create(&(philos[i]), NULL, &life, &(param[i]));
		pthread_create(&(philos[nb + i]), NULL, &check, &(param[i]));
		i = i + 2;
	}
	return (philos);
}	
