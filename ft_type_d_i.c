/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:43:35 by aliens            #+#    #+#             */
/*   Updated: 2021/01/10 18:25:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_size(n / 10));
}

int			ft_type_d_i(int i)
{
	ft_putnbr_fd(i, 1);
	if (!i)
		return (1);
	return (ft_size(i));
}
