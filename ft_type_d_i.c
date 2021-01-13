/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:43:35 by aliens            #+#    #+#             */
/*   Updated: 2021/01/13 15:58:16 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_size(n / 10));
}

int			ft_type_d_i(int n)
{
	int	i;
	int j;

	i = -1;
	j = 0;
	if (list.flags[0] == 3)
		while (++i < list.prec[0] - ft_size(n))
			write(1, "0", 1);
	else if (list.flags[0] == 2)
	{
		if (list.flags[1])
			j = list.prec[1] < ft_size(n) ? ft_size(n) : list.prec[1];
		else
			j = ft_size(n);
		while (++i < list.prec[0] - j)
			write(1, " ", 1);
	}
	else if (list.flags[0] == 4)
	{
		if (list.flags[1])
			j = list.prec[1] < ft_size(n) ? ft_size(n) : list.prec[1];
		else
			j = ft_size(n);
		while (++i < list.prec[0] - j)
			write(1, " ", 1);
	}
	if (list.flags[1])
	{
		i = -1;
		while (++i < list.prec[1] - ft_size(n))
			write(1, "0", 1);
	}
	ft_putnbr_fd(n, 1);
	if (list.flags[0] == 1)
	{
		i = -1;
		if (list.flags[1])
			j = list.prec[1] < ft_size(n) ? ft_size(n) : list.prec[1];
		else
			j = ft_size(n);
		while (++i < list.prec[0] - j)
			write(1, " ", 1);
	}
	j = list.prec[0] < list.prec[1] ? list.prec[1] : list.prec[0];
	return (j < ft_size(n) ? ft_size(n) : j);
}
