/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:06 by aliens            #+#    #+#             */
/*   Updated: 2021/01/28 14:49:22 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int			ft_type_p_dot(char *dst, char *hex, unsigned long ptr2)
{
	int i;
	int j;
	int dot;
	int p_i;
	int size;

	i = -1;
	j = -1;
	size = list.prec[1] < ft_hex_size(ptr2) ? ft_hex_size(ptr2) : list.prec[1];
	p_i = ft_hex_size(ptr2);
	dot = !ptr2 && !list.prec[1] ? 1 : 0;
	if (list.flags[0] == 4 || list.flags[0] == 2)
		while (-dot + ++i < list.prec[0] - size - 2)
			write(1, " ", 1);
	ft_putstr("0x");
	while (++j < list.prec[1] - p_i)
		write(1, "0", 1);
	while (p_i--)
	{
		dst[p_i] = hex[ptr2 % 16];
		ptr2 /= 16;
	}
	dot ? size-- : ft_putstr(dst);
	free(dst);
	if (list.flags[0] == 1)
		while (++i < list.prec[0] - size - 2)
			write(1, " ", 1);
	return (size + i + 2);
}

int			ft_type_p(void *ptr, char *hex)
{
	unsigned long	ptr2;
	char			*dst;
	int				size;
	int				i;
	int				p_i;
	int				dot;

	i = 0;
	ptr2 = (unsigned long)ptr;
	size = ft_hex_size(ptr2);
	p_i = size;
	if (!(dst = (char *)ft_calloc(sizeof(char), size + 1)))
		return (0);
	if (list.flags[1])
		return (ft_type_p_dot(dst, hex, ptr2));
	dot = list.flags[0] == 3 && !(unsigned long)ptr && !list.prec[0] ? 1 : 0;
	if (list.flags[0] == 4)
		while (i++ < list.prec[0] - size - 2 - dot)
			write(1, " ", 1);
	ft_putstr("0x");
	if (list.flags[0] == 2)
		while (i++ < list.prec[0] - size - 2 - dot)
			write(1, "0", 1);
	else if (list.flags[0] == 3)
		while (i++ < list.prec[0] - size - dot)
			write(1, "0", 1);
	while (p_i--)
	{
		dst[p_i] = hex[ptr2 % 16];
		ptr2 /= 16;
	}
	dot ? size-- : ft_putstr(dst);
	free(dst);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - size - 2)
			write(1, " ", 1);
	return (i ? size + i + 1 : size + 2);
}
