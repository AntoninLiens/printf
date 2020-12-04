/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_upperX.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:00:48 by aliens            #+#    #+#             */
/*   Updated: 2020/12/04 15:49:12 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 10, a + 1));
}


int			ft_convert_x(unsigned int n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n)
	{
		ft_putchar_fd(base[n / 16], 1);
		ft_convert_x(n % 16);
	}
	return (ft_size(n, 0));
}
