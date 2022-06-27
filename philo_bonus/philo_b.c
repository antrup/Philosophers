/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:49:21 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/05 19:59:16 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_nb_args(void)
{
	write(2, "usage: number_of_philosophers time_to_die time_to_eat", 53);
	write(2, " time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 59);
	return (-1);
}

int	philo(int id, t_bag bag, char **argv)
{
	t_param			params;
	pthread_t		thephilo;
	pthread_t		checkt;
	int				ret;

	init_param(&params, argv, id);
	ret = init_param2(&params, bag, argv);
	if (ret == 1)
		exit(1);
	pthread_create(&thephilo, NULL, &life, &params);
	pthread_create(&checkt, NULL, &check, &params);
	pthread_detach(thephilo);
	pthread_detach(checkt);
	while (1)
		usleep(1000000);
	return (0);
}

int	call_processes(char **argv, t_bag bag, pid_t **list)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pid = fork();
		list[0][i] = pid;
		if (pid == -1)
			return (1);
		if (pid == 0)
		{	
			free(list[0]);
			philo(i + 1, bag, argv);
			exit(0);
		}
		i++;
	}	
	waitpid(-1, &i, 0);
	if (WEXITSTATUS(i) == 1)
		ps_killer(*list, ft_atoi(argv[1]));
	else
		ps_waiter(*list, ft_atoi(argv[1]));
	return (0);
}

int	init(char **argv)
{
	t_bag	bag;
	pid_t	*list;

	list = malloc(sizeof(pid_t) * ft_atoi(argv[1]));
	if (!list)
		return (1);
	bag.sem[0] = sem_open("forks", O_CREAT, 0777, ft_atoi(argv[1]));
	bag.sem[1] = sem_open("printer", O_CREAT, 0777, 1);
	if (bag.sem[0] == SEM_FAILED || bag.sem[1] == SEM_FAILED)
		return (sem_fail());
	bag.start_time = timeformat();
	call_processes(argv, bag, &list);
	free(list);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*semname;

	sem_unlink("forks");
	sem_unlink("printer");
	if (argc < 5 || argc > 6)
		return (error_nb_args());
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0 || (argc == 6 && ft_atoi(argv[5]) <= 0))
		return (1);
	init(argv);
	sem_unlink("forks");
	sem_unlink("printer");
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		semname = ft_itoa(i + 1);
		if (!semname)
			return (1);
		sem_unlink(semname);
		free(semname);
		i++;
	}
	return (0);
}
