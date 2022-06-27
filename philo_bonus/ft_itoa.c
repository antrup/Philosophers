/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:08:50 by atruphem          #+#    #+#             */
/*   Updated: 2021/07/05 19:55:46 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_creastr(char *result, long n, int count)
{
	result[count] = '\0';
	while (n / 10 >= 1)
	{
		result[count - 1] = n % 10 + 48;
		n = n / 10;
		count--;
	}
	result[count - 1] = n % 10 + 48;
}

char	*ft_itoa(int n)
{
	long	tmp;
	int		count;
	char	*result;
	long	nl;

	count = 1;
	nl = n;
	tmp = nl;
	while (tmp / 10 >= 1)
	{
		count++;
		tmp = tmp / 10;
	}
	result = malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	ft_creastr(result, nl, count);
	return (result);
}
