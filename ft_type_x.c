/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:18:03 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 13:52:15 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(unsigned int n)
{
	if (n < 16)
		return (1);
	return (1 + ft_size(n / 16));
}

int			ft_flags_before(int size, int i)
{
	if (list.flags[0] == 2)
		while (i++ < list.prec[0] - size)
		{
			if (list.flags[1])
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
	else if (list.flags[0] == 3)
		while (i++ < list.prec[0] - size)
			write(1, "0", 1);
	else if (list.flags[0] == 4)
		while (i++ < list.prec[0] - size)
			write(1, " ", 1);
	return (i);
}

int			ft_type_x_dot(unsigned int n, char *base, char *res)
{
	int		size;
	int		x_i;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = list.prec[1] < ft_size(n) ? ft_size(n) : list.prec[1];
	x_i = size;
	i = ft_flags_before(size, i);
	while (j++ < size - x_i)
		write(1, "0", 1);
	while (x_i--)
	{
		res[x_i] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - size)
			write(1, " ", 1);
	return (size + i - 1);
}

int			ft_type_x(unsigned int n, char *base)
{
	char	*res;
	int		size;
	int		i;
	int		x_i;

	i = 0;
	size = ft_size(n);
	x_i = size;
	if (!(res = ft_calloc(sizeof(char), size + 1)))
		return (0);
	if (list.flags[1])
		return (ft_type_x_dot(n, base, res));
	i = ft_flags_before(size, i);
	while (x_i--)
	{
		res[x_i] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - size)
			write(1, " ", 1);
	return (i ? ft_size(n) + i : ft_size(n) + 1);
}
