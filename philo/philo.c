/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:49:12 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/02 18:58:34 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_nb_args(void)
{
	write(2, "usage: number_of_philosophers time_to_die time_to_eat", 53);
	write(2, " time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 59);
	return (-1);
}

void	wait_philos(pthread_t	*philos, int nb)
{
	int	i;

	i = 0;
	while (i < (nb * 2))
	{
		pthread_join (philos[i], NULL);
		i++;
	}
}

int	god(char **argv, int argc)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*lunch;
	pthread_t		*philos;
	int				smb_died;
	t_param			*params;

	forks = create_forks(ft_atoi(argv[1]));
	if (!forks)
		return (1);
	lunch = create_forks(ft_atoi(argv[1]));
	if (!lunch)
		return (clean_one(&forks, ft_atoi(argv[1])));
	params = init_param(argv, lunch, &smb_died);
	if (!params)
		return (clean_two(&forks, &lunch, ft_atoi(argv[1])));
	int_param3(&params, argv, forks);
	smb_died = init_param2(&params, ft_atoi(argv[1]), argc, argv);
	if (smb_died == 1)
		return (clean_four(&forks, &lunch, &params));
	philos = init_thread(ft_atoi(argv[1]), params);
	if (!philos)
		return (clean_three(&forks, &lunch, &params));
	wait_philos(philos, ft_atoi(argv[1]));
	clean_all(&forks, &lunch, &params, &philos);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_nb_args());
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0 || (argc == 6 && ft_atoi(argv[5]) <= 0))
		return (1);
	return (god(argv, argc));
}
