/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:06 by aliens            #+#    #+#             */
/*   Updated: 2021/01/29 17:45:56 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int	ft_flags_before(int size, int dot, int i)
{
	if (list.flags[0] == 4)
		while (i++ < list.prec[0] - size - 2 - dot)
			write(1, " ", 1);
	ft_putstr("0x");
	if (list.flags[0] == 2 && !list.flags[1])
		while (i++ < list.prec[0] - size - 2 - dot)
			write(1, "0", 1);
	else if (list.flags[0] == 3)
		while (i++ < list.prec[0] - size - dot)
			write(1, "0", 1);
	return (i);
}

static char	*ft_make_the_dst(void *ptr, int size, char *hex)
{
	unsigned long	ptr2;
	char			*dst;

	ptr2 = (unsigned long)ptr;
	if (!(dst = (char *)ft_calloc(sizeof(char), size + 1)))
		return (0);
	while (size--)
	{
		dst[size] = hex[ptr2 % 16];
		ptr2 /= 16;
	}
	return (dst);
}

int			ft_type_p_dot(void *ptr, char *dst, int s)
{
	int	i;
	int	j;
	int	dot;
	int	size;

	i = -1;
	j = -1;
	size = list.prec[1] < s ? s : list.prec[1];
	dot = !(unsigned long)ptr && !list.prec[1] ? 1 : 0;
	if (list.flags[0] == 2 || list.flags[0] == 4)
		while (-dot + ++i < list.prec[0] - size - 2)
			write(1, " ", 1);
	ft_putstr("0x");
	while (++j < list.prec[1] - ft_hex_size((unsigned long)ptr))
		write(1, "0", 1);
	dot ? size-- : ft_putstr(dst);
	free(dst);
	if (list.flags[0] == 1)
		while (++i < list.prec[0] - size - 2)
			write(1, " ", 1);
	return (size + i + 2);
}

int			ft_type_p(void *ptr, char *hex)
{
	int		i;
	int		size;
	char	*dst;
	int		dot;

	i = 0;
	size = ft_hex_size((unsigned long)ptr);
	dst = ft_make_the_dst(ptr, size, hex);
	if (list.flags[1])
		return (ft_type_p_dot(ptr, dst, size));
	dot = list.flags[0] == 3 && !(unsigned long)ptr && !list.prec[0] ? 1 : 0;
	i = ft_flags_before(size, dot, i);
	dot ? size-- : ft_putstr(dst);
	free(dst);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - size - 2)
			write(1, " ", 1);
	return (i ? size + i + 1 : size + 2);
}
