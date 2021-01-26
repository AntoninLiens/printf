/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:18:03 by aliens            #+#    #+#             */
/*   Updated: 2021/01/26 18:40:22 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int			ft_flags_before(int size, int i, int dot)
{
	if (list.flags[0] == 2)
		while (-dot + i++ < list.prec[0] - size)
		{
			if (list.flags[1])
				write(1, " ", 1);
			else
				write(1, "0", 1);
		}
	else if (list.flags[0] == 3)
		while (-dot + i++ < list.prec[0] - size)
			write(1, "0", 1);
	else if (list.flags[0] == 4)
		while (-dot + i++ < list.prec[0] - size)
			write(1, " ", 1);
	return (i);
}

int			ft_type_x_dot(unsigned int n, char *base, char *res)
{
	int		size;
	int		x_i;
	int		dot;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = list.prec[1] < ft_hex_size(n) ? ft_hex_size(n) : list.prec[1];
	x_i = ft_hex_size(n);
	dot = !n && !list.prec[1] ? 1 : 0;
	i = ft_flags_before(size, i, dot);
	while (j++ < size - x_i)
		write(1, "0", 1);
	while (x_i--)
	{
		res[x_i] = base[n % 16];
		n /= 16;
	}
	dot ? size-- : ft_putstr(res);
	free(res);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - size)
			write(1, " ", 1);
	return (size + --i);
}

int			ft_type_x(unsigned int n, char *base)
{
	char	*res;
	int		size;
	int		i;
	int		x_i;
	int		dot;

	i = 0;
	size = ft_hex_size(n);
	x_i = size;
	if (!(res = (char *)ft_calloc(sizeof(char), size + 1)))
		return (0);
	if (list.flags[1])
		return (ft_type_x_dot(n, base, res));
	dot = !n && list.flags[0] == 3 && !list.prec[0] ? 1 : 0;
	i = ft_flags_before(size, i, dot);
	while (x_i--)
	{
			res[x_i] = base[n % 16];
			n /= 16;
	}
	dot ? size-- : ft_putstr(res);
	free(res);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - size)
			write(1, " ", 1);
	return (i ? size + --i : size);
}
