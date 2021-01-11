/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_upperx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:45:03 by aliens            #+#    #+#             */
/*   Updated: 2021/01/10 18:08:23 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(int n)
{
	if (n < 16)
		return (1);
	return (1 + ft_size(n / 16));
}

int			ft_type_upperx(unsigned int n)
{
	unsigned int	ret;
	size_t			i;
	char			*base;
	char			*res;

	ret = n;
	base = "0123456789ABCDEF";
	i = ft_size(n);
	if (!(res = ft_calloc(sizeof(char), i + 1)))
		return (0);
	while (i--)
	{
		res[i] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	return (ft_size(ret));
}
