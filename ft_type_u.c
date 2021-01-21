/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:44 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 14:13:30 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int				ft_type_u_dot(int n)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	j = -1;
	size = list.prec[1] < ft_ten_size(n) ? ft_ten_size(n) : list.prec[1];
	if (list.flags[0] == 2 || list.flags[0] == 4)
		while (++i < list.prec[0] - size)
			write(1, " ", 1);
	while (++j < size - ft_ten_size(n))
		write(1, "0", 1);
	if (n < 0)
	{
		ft_putnbr_ui(UINT_MAX + (unsigned int)n + 1);
		return (ft_ten_size(UINT_MAX + (unsigned int)n + 1));
	}
	else
		ft_putnbr_ui((unsigned int)n);
	if (list.flags[0] == 1)
		while (++i < list.prec[0] - size)
			write(1, " ", 1);
	return (size + i);
}

int				ft_type_u(int n)
{
	int	i;

	i = 0;
	if (list.flags[1])
		return (ft_type_u_dot(n));
	else if (list.flags[0] == 2 || list.flags[0] == 3)
		while (i++ < list.prec[0] - ft_ten_size(n))
			write(1, "0", 1);
	else if (list.flags[0] == 4)
		while (i++ < list.prec[0] - ft_ten_size(n))
			write(1, " ", 1);
	if (n < 0)
	{
		ft_putnbr_ui(UINT_MAX + (unsigned int)n + 1);
		return (ft_ten_size(UINT_MAX + (unsigned int)n + 1));
	}
	else
		ft_putnbr_ui((unsigned int)n);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - ft_ten_size(n))
			write(1, " ", 1);
	return (i ? ft_ten_size(n) + i - 1 : ft_ten_size(n));
}
