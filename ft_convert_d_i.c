/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:11:17 by aliens            #+#    #+#             */
/*   Updated: 2021/01/04 14:55:34 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	else if (n < 0)
		return (ft_size(n / -10, a + 2));
	else
		return (ft_size(n / 10, a + 1));
}

int			ft_convert_d_i(int i)
{
	ft_putnbr_fd(i, 1);
	return (ft_size(i, 0));
}
