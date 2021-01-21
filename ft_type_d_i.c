/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:43:35 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 14:09:31 by aliens           ###   ########.fr       */
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

static int		ft_flags_before(unsigned int nbr, int neg)
{
	int i;

	i = 0;
	if (list.flags[0] == 4)
		while (i++ < list.prec[0] - ft_ten_size(nbr))
			write(1, " ", 1);
	if (neg)
		write(1, "-", 1);
	if (list.flags[0] == 2)
		while (i++ < list.prec[0] - ft_ten_size(nbr))
			write(1, "0", 1);
	else if (list.flags[0] == 3)
		while (i++ < list.prec[0] - ft_ten_size(nbr))
			write(1, "0", 1);
	return (i);
}

int				ft_type_d_i(int n, int neg)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	if (n < 0)
	{
		nbr = -n;
		neg = 1;
		i++;
	}
	else
		nbr = n;
	if (list.flags[1])
		return (ft_type_d_i_dot(nbr, neg));
	ft_flags_before(nbr, neg);
	ft_putnbr_ui(nbr);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - ft_ten_size(nbr))
			write(1, " ", 1);
	return (i ? ft_ten_size(n) + i - 1 : ft_ten_size(nbr));
}
