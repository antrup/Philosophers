/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:54:25 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/02 18:58:58 by atruphem         ###   ########.fr       */
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

typedef struct s_param
{
	int				id;
	int				nb_p;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				*smb_died;
	long			start_time;
	long			last_eat;
	int				nb_eat;
	int				max_eat;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	*lunch;
	pthread_mutex_t	*printer;
}					t_param;

int				error_nb_args(void);
pthread_mutex_t	*create_forks(int nb);
void			print_msg(t_param *data, char *msg);
void			eat(t_param *data);
void			precise_sleep(long	zzz);
void			*life(void *params);
long			timeformat(void);
void			*check(void *params);
t_param			*init_param(char **argv,
					pthread_mutex_t *lunch, int *smb_died);
int				init_param2(t_param **params, int nb, int argc, char **argv);
pthread_t		*init_thread(int nb, t_param *param);
int				ft_atoi(const char *str);
int				clean_four(pthread_mutex_t **forks, pthread_mutex_t **lunch,
					t_param **params);
int				clean_three(pthread_mutex_t **forks, pthread_mutex_t **lunch,
					t_param **params);
void			clean_all(pthread_mutex_t **forks, pthread_mutex_t **lunch,
					t_param **params, pthread_t **philos);
int				clean_two(pthread_mutex_t **forks, pthread_mutex_t **lunch,
					int nb);
int				clean_one(pthread_mutex_t **forks, int nb);
void			int_param3(t_param **params, char **argv,
					pthread_mutex_t *forks);
#endif
