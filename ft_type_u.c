/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:44 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 12:11:48 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static void		ft_putnbr_ui(unsigned int n)
{
	if (n > 9)
		ft_putnbr_ui(n / 10);
	ft_putchar_fd('0' + n % 10, 1);
}

static int		ft_size(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_size(n / 10));
}

int				ft_type_u_dot(int n)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	j = -1;
	size = list.prec[1] < ft_size(n) ? ft_size(n) : list.prec[1];
	if (list.flags[0] == 2 || list.flags[0] == 4)
		while (++i < list.prec[0] - size)
			write(1, " ", 1);
	while (++j < size - ft_size(n))
		write(1, "0", 1);
	if (n < 0)
	{
		ft_putnbr_ui(UINT_MAX + (unsigned int)n + 1);
		return (ft_size(UINT_MAX + (unsigned int)n + 1));
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
		while (i++ < list.prec[0] - ft_size(n))
			write(1, "0", 1);
	else if (list.flags[0] == 4)
		while (i++ < list.prec[0] - ft_size(n))
			write(1, " ", 1);
	if (n < 0)
	{
		ft_putnbr_ui(UINT_MAX + (unsigned int)n + 1);
		return (ft_size(UINT_MAX + (unsigned int)n + 1));
	}
	else
		ft_putnbr_ui((unsigned int)n);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - ft_size(n))
			write(1, " ", 1);
	return (i ? ft_size(n) + i - 1 : ft_size(n));
}
