/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:58:16 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/05 19:59:11 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ps_killer(pid_t *list, int nb)
{	
	int	i;

	i = 0;
	while (i < nb)
	{
		kill(list[i], SIGTERM);
		i++;
	}
}

void	ps_waiter(pid_t *list, int nb)
{	
	int	i;

	i = 0;
	while (i < nb)
	{
		waitpid(list[i], NULL, 0);
		i++;
	}
}
