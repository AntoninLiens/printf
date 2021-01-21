/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:43:35 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 15:11:51 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int				ft_type_d_i_dot(int n, int neg)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	j = -1;
	i += neg;
	size = list.prec[1] < ft_ten_size(n) ? ft_ten_size(n) : list.prec[1];
	if (list.flags[0] == 2 || list.flags[0] == 4)
		while (++i < list.prec[0] - size)
			write(1, " ", 1);
	if (neg)
		write(1, "-", 1);
	else if (list.flags[0] == 3)
		while (++i < list.prec[0] - size)
			write(1, "0", 1);
	while (++j < size - ft_ten_size(n))
		write(1, "0", 1);
	ft_putnbr_ui(n);
	if (list.flags[0] == 1)
		while (++i < list.prec[0] - size)
			write(1, " ", 1);
	return (size + i);
}

static int		ft_flags_before(int neg, int i, int size)
{
	if (list.flags[0] == 4)
		while (i++ < list.prec[0] - size)
			write(1, " ", 1);
	if (neg)
		write(1, "-", 1);
	if (list.flags[0] == 2)
		while (i++ < list.prec[0] - size)
			write(1, "0", 1);
	else if (list.flags[0] == 3)
	{
		if (neg)
			while (i++ < list.prec[0] - size + 1)
				write(1, "0", 1);
		else
			while (i++ < list.prec[0] - size)
				write(1, "0", 1);
	}
	return (i);
}

int				ft_type_d_i(int n, int neg)
{
	int				i;
	unsigned int	nbr;
	int				size;

	i = 0;
	if (n < 0)
	{
		nbr = -n;
		neg = 1;
		i++;
	}
	else
		nbr = n;
	size = ft_ten_size(nbr);
	if (list.flags[1])
		return (ft_type_d_i_dot(nbr, neg));
	i = ft_flags_before(neg, i, size);
	ft_putnbr_ui(nbr);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - size)
			write(1, " ", 1);
	return (i ? size + i - 1 : size);
}
