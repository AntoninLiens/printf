/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_lowerx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:07:44 by aliens            #+#    #+#             */
/*   Updated: 2021/01/06 17:08:20 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(unsigned int n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 16, a + 1));
}

int			ft_type_lowerx(unsigned int n)
{
	unsigned int	ret;
	size_t			i;
	char			*base;
	char			*res;

	ret = n;
	base = "0123456789abcdef";
	i = ft_size(n, 0);
	if (!(res = ft_calloc(sizeof(char), i + 1)))
		return (0);
	while (i--)
	{
		res[i] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	return (ft_size(ret, 0));
}
