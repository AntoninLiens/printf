/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:18:03 by aliens            #+#    #+#             */
/*   Updated: 2021/01/18 15:30:59 by aliens           ###   ########.fr       */
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
		while (++i < list.prec[0] - size)
			write(1, " ", 1);
	else if (list.flags[0] == 4)
		while (++i < list.prec[0] - size)
			write(1, "0", 1);
	return (i);
}

int			ft_type_x_dot(unsigned int n, char *base, char *res)
{
	int		u_size;
	int		size;
	int		i;
	int		j;

	i = -1;
	j = -1;
	size = list.prec[1] < ft_size(n) ? ft_size(n) : list.prec[1];
	i = ft_flags_before(size, i);
	while (++j < size - ft_size(n))
		write(1, "0", 1);
	u_size = ft_size(n);
	while (u_size--)
	{
		res[i] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	if (list.flags[0] == 1)
		while (++i < list.prec[0] - size)
			write(1, " ", 1);
	return (size + i);
}

int			ft_type_x(unsigned int n, char *base)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = ft_size(n);
	if (!(res = ft_calloc(sizeof(char), size + 1)))
		return (0);
	if (list.flags[1])
		return (ft_type_x_dot(n, base, res));
	i = ft_flags_before(size, i);
	while (size--)
	{
		res[i] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free(res);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - ft_size(n))
			write(1, " ", 1);
	return (i ? ft_size(n) + i - 1 : ft_size(n));
}
