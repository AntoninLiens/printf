/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:20 by aliens            #+#    #+#             */
/*   Updated: 2021/01/26 18:21:57 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int		ft_type_s_dot(char *str)
{
	int i;
	int j;
	int	s;

	s = list.prec[1] < (int)ft_strlen(str) ? list.prec[1] : (int)ft_strlen(str);
	i = -1;
	j = -1;
	if (list.flags[0] == 2)
		while (++i < list.prec[0] - s)
			write(1, "0", 1);
	else if (list.flags[0] == 4)
		while (++i < list.prec[0] - s)
			write(1, " ", 1);
	while (++j < s)
		ft_putchar(str[j]);
	if (list.flags[0] == 1)
		while (++i < list.prec[0] - s)
			write(1, " ", 1);
	return (j + i);
}

int		ft_type_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	if (list.flags[1])
		return (ft_type_s_dot(str));
	if (list.flags[0] == 2)
		while (i++ < list.prec[0] - (int)ft_strlen(str))
			write(1, "0", 1);
	else if (list.flags[0] == 4)
		while (i++ < list.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	if (list.flags[0] == 3)
	{
		while (i < list.prec[0] && i < (int)ft_strlen(str))
			ft_putchar(str[i++]);
		return (i);
	}
	else
		ft_putstr(str);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	return (ft_strlen(str) + (i ? --i : i));
}
