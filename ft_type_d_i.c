/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:07:22 by aliens            #+#    #+#             */
/*   Updated: 2021/01/07 16:44:50 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	else if (n < 0)
		return (ft_size(n / -10, a + 2));
	return (ft_size(n / 10, a + 1));
}

int			ft_type_d_i(int i)
{
	ft_putnbr_fd(i, 1);
	if (!i)
		return (1);
	return (ft_size(i, 0));
}
