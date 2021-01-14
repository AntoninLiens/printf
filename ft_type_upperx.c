/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_upperx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:45:03 by aliens            #+#    #+#             */
/*   Updated: 2021/01/14 15:05:42 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(unsigned int n)
{
	if (n < 16)
		return (1);
	return (1 + ft_size(n / 16));
}

int			ft_type_upperx(unsigned int n)
{
	unsigned int	ret;
	int				i;
	int				j;
	char			*base;
	char			*res;

	i = -1;
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
		{
			if (list.prec[1])
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
	}
	if (list.flags[1])
	{
		i = -1;
		while (++i < list.prec[1] - ft_size(n))
			write(1, "0", 1);
	}
	ret = n;
	base = "0123456789ABCDEF";
	i = ft_size(n);
	if (!(res = ft_calloc(sizeof(char), i + 1)))
		return (0);
	while (i--)
	{
		res[i] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	if (list.flags[0] == 1)
	{
		i = -1;
		if (list.flags[1])
			j = list.prec[1] < ft_size(n) ? ft_size(n) : list.prec[1];
		while (++i < list.prec[0] - j)
			write(1, " ", 1);
	}
	j = list.prec[0] < list.prec[1] ? list.prec[1] : list.prec[0];
	return (j < ft_size(n) ? ft_size(n) : j);
}
