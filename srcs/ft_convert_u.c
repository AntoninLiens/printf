/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:47:33 by aliens            #+#    #+#             */
/*   Updated: 2020/12/07 16:43:03 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void		ft_putnbr_ui(unsigned int n)
{
	if (n < 0)
		ft_putchar_fd('-', 1);
	if (n > 9)
		ft_putnbr_ui(n / 10);
	ft_putchar_fd('0' + n % 10, 1);
}

static int		ft_size(int n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 10, a + 1));
}

int				ft_convert_u(int n)
{
	int n2;

	n2 = n;
	if (n < 0)
	{
		ft_putnbr_ui(UINT_MAX + (unsigned int)n + 1);
		return (ft_size(UINT_MAX + n2 + 1, 0));
	}
	else
		ft_putnbr_ui((unsigned int)n);
	return (ft_size(n2, 0));
}
