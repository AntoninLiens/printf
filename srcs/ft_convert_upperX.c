/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_upperx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:35:18 by aliens            #+#    #+#             */
/*   Updated: 2020/12/07 13:03:17 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 10, a + 1));
}

int			ft_convert_upperx(unsigned int n)
{
	unsigned int	res;
	char			*base;

	res = n;
	base = "0123456789ABCDEF";
	if (n > 16)
	{
		ft_putchar_fd(base[n / 16], 1);
		ft_convert_upperx(n % 16);
	}
	ft_putchar_fd(n % 16, 1);
	return (ft_size(res, 0));
}
