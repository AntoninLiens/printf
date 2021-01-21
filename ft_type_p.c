/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:06 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 14:29:02 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int			ft_type_p(void *ptr)
{
	unsigned long	ptr2;
	char			*hex;
	char			*dst;
	int				size;

	ptr2 = (unsigned long)ptr;
	hex = "0123456789abcdef";
	size = ft_sixteen_size(ptr2);
	ft_putstr("0x");
	if (!(dst = ft_calloc(sizeof(char), size + 1)))
		return (0);
	while (size--)
	{
		dst[size] = hex[ptr2 % 16];
		ptr2 /= 16;
	}
	ft_putstr(dst);
	free(dst);
	return (ft_sixteen_size((unsigned long)ptr) + 2);
}
