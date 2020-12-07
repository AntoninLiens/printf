/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_lowerx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:11:35 by aliens            #+#    #+#             */
/*   Updated: 2020/12/07 13:03:43 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 10, a + 1));
}


int			ft_convert_lowerx(unsigned int n)
{
	unsigned int	res;
	char			*base;

	res = n;
	base = "0123456789abcdef";
	if (n > 16)
	{
		ft_putchar_fd(base[n / 16], 1);
		ft_convert_lowerx(n % 16);
	}
	ft_putchar_fd(n % 16, 1);
	return (ft_size(res, 0));
}
