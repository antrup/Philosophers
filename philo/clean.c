/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:21:54 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/01 13:34:49 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_one(pthread_mutex_t **forks, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&(forks[0][i]));
		i++;
	}
	free(forks[0]);
	return (1);
}

int	clean_two(pthread_mutex_t **forks, pthread_mutex_t **lunch, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&(forks[0][i]));
		pthread_mutex_destroy(&(lunch[0][i]));
		i++;
	}
	free(forks[0]);
	free(lunch[0]);
	return (1);
}

int	clean_three(pthread_mutex_t **forks, pthread_mutex_t **lunch,
	t_param **params)
{
	int		nb;
	int		i;

	pthread_mutex_destroy(params[0][0].printer);
	free(params[0][0].printer);
	nb = params[0][0].nb_p;
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&(forks[0][i]));
		pthread_mutex_destroy(&(lunch[0][i]));
		i++;
	}
	free(forks[0]);
	free(lunch[0]);
	free(params[0]);
	return (1);
}

int	clean_four(pthread_mutex_t **forks, pthread_mutex_t **lunch,
	t_param **params)
{
	int		nb;
	int		i;

	nb = params[0][0].nb_p;
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&(forks[0][i]));
		pthread_mutex_destroy(&(lunch[0][i]));
		i++;
	}
	free(forks[0]);
	free(lunch[0]);
	free(params[0]);
	return (1);
}

void	clean_all(pthread_mutex_t **forks, pthread_mutex_t **lunch,
		t_param **params, pthread_t **philos)
{
	int		nb;
	int		i;

	pthread_mutex_destroy(params[0][0].printer);
	free(params[0][0].printer);
	nb = params[0][0].nb_p;
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&(forks[0][i]));
		pthread_mutex_destroy(&(lunch[0][i]));
		i++;
	}
	free(forks[0]);
	free(lunch[0]);
	free(params[0]);
	free(philos[0]);
}
