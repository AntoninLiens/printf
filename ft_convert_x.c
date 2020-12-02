/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:11:35 by aliens            #+#    #+#             */
/*   Updated: 2020/12/02 16:49:46 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 10, a + 1));
}


int	ft_convert_x(unsigned int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n)
	{
		ft_putchar_fd(base[n % 16], 1);
		ft_convert_x(n / 16);
	}
	return (ft_size(n, 0));
}
