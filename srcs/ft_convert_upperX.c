/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_upperx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:35:18 by aliens            #+#    #+#             */
/*   Updated: 2020/12/07 14:52:59 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 16, a + 1));
}

int			ft_convert_upperx(unsigned int n)
{
	unsigned int	ret;
	size_t			i;
	char			*base;
	char			*res;

	ret = n;
	base = "0123456789ABCDEF";
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
