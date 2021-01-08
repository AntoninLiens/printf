/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:06 by aliens            #+#    #+#             */
/*   Updated: 2021/01/08 16:44:17 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_size(unsigned long n, int a)
{
	if (!n)
		return (a);
	return (ft_size(n / 16, a + 1));
}

int			ft_type_p(void *ptr)
{
	unsigned long	ptr2;
	char			*hex;
	char			*dst;
	int				size;

	ptr2 = (unsigned long)ptr;
	hex = "0123456789abcdef";
	size = ft_size(ptr2, 0);
	ft_putstr_fd("0x", 1);
	if (!(dst = ft_calloc(sizeof(char), size + 1)))
		return (0);
	while (size--)
	{
		dst[size] = hex[ptr2 % 16];
		ptr2 /= 16;
	}
	ft_putstr_fd(dst, 1);
	free(dst);
	return (ft_size((unsigned long)ptr, 0) + 2);
}
