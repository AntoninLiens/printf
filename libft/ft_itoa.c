/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:45:08 by aliens            #+#    #+#             */
/*   Updated: 2020/12/02 09:15:27 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	else if (n < 0)
		return (ft_size(n / -10, a + 2));
	else
		return (ft_size(n / 10, a + 1));
}

char		*ft_itoa(int n)
{
	int		size;
	int		n2;
	char	*dst;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	size = n ? ft_size(n, 0) : 1;
	n2 = n < 0 ? -n : n;
	if (!(dst = ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	ft_memset(dst, '0', size);
	if (!n)
		return (dst);
	while (size)
	{
		dst[size - 1] = n2 % 10 + '0';
		if (!n2 && !size - 1)
			dst[size - 1] = '-';
		n2 /= 10;
		size--;
	}
	return (dst);
}
