/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:44 by aliens            #+#    #+#             */
/*   Updated: 2021/01/08 16:45:00 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static void		ft_putnbr_ui(unsigned int n)
{
	if (n < 0)
		ft_putchar_fd('-', 1);
	if (n > 9)
		ft_putnbr_ui(n / 10);
	ft_putchar_fd('0' + n % 10, 1);
}

static int		ft_size(unsigned int n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 10, a + 1));
}

int				ft_type_u(int n)
{
	if (n < 0)
	{
		ft_putnbr_ui(UINT_MAX + (unsigned int)n + 1);
		return (ft_size(UINT_MAX + (unsigned int)n + 1, 0));
	}
	else
		ft_putnbr_ui((unsigned int)n);
	return (ft_size((unsigned int)n, 0));
}
