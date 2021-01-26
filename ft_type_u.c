/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:44 by aliens            #+#    #+#             */
/*   Updated: 2021/01/26 19:06:16 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int				ft_type_u_dot(int n)
{
	int	i;
	int	j;
	int	size;
	int dot;

	i = -1;
	j = -1;
	size = list.prec[1] < ft_ten_size(n) ? ft_ten_size(n) : list.prec[1];
	dot = !n && !list.prec[1] ? 1 : 0;
	if (list.flags[0] == 2 || list.flags[0] == 4)
		while (-dot + ++i < list.prec[0] - size)
			write(1, " ", 1);
	while (++j < size - ft_ten_size(n))
		write(1, "0", 1);
	dot ? size-- : ft_putnbr_ui(n);
	if (list.flags[0] == 1)
		while (++i < list.prec[0] - size)
			write(1, " ", 1);
	return (size + i);
}

int				ft_type_u(int n)
{
	int				i;
	int				dot;
	int				size;
	unsigned int	nb;

	nb = n < 0 ? UINT_MAX + n + 1 : n;
	size = ft_ten_size(nb);
	i = 0;
	if (list.flags[1])
		return (ft_type_u_dot(nb));
	dot = !n && list.flags[0] == 3 && !list.prec[0] ? 1 : 0;
	if (list.flags[0] == 2 || list.flags[0] == 3)
		while (-dot + i++ < list.prec[0] - size)
			write(1, "0", 1);
	else if (list.flags[0] == 4)
		while (-dot + i++ < list.prec[0] - size)
			write(1, " ", 1);
	dot ? size-- : ft_putnbr_ui(nb);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - size)
			write(1, " ", 1);
	return (i ? size + --i : size);
}
