/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:54:25 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/06 14:46:09 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_param
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start_time;
	long			last_eat;
	int				nb_eat;
	int				max_eat;
	sem_t			*fork;
	sem_t			*printer;
	sem_t			*lunch;
}					t_param;

typedef struct s_bag
{
	sem_t	*sem[2];
	long	start_time;
}				t_bag;

int		ft_atoi(const char *str);
void	init_param(t_param *params, char **argv, int id);
int		init_param2(t_param *params, t_bag bag, char **argv);
void	*check(void *params);
void	*life(void *params);
void	print_msg(t_param *data, char *msg);
long	timeformat(void);
int		sem_fail(void);
void	ps_killer(pid_t *list, int nb);
void	ps_waiter(pid_t *list, int nb);
char	*ft_itoa(int n);

#endif
