/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:20 by aliens            #+#    #+#             */
/*   Updated: 2021/02/25 16:00:26 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_type_s_dot(char *str)
{
	int i;
	int j;
	int	s;

	if (g_plist.prec[1] < (int)ft_strlen(str))
		s = g_plist.prec[1];
	else
		s = (int)ft_strlen(str);
	i = -1;
	j = -1;
	if (g_plist.flags[0] == 2)
		while (++i < g_plist.prec[0] - s)
			write(1, "0", 1);
	else if (g_plist.flags[0] == 4)
		while (++i < g_plist.prec[0] - s)
			write(1, " ", 1);
	while (++j < s)
		ft_putchar(str[j]);
	if (g_plist.flags[0] == 1)
		while (++i < g_plist.prec[0] - s)
			write(1, " ", 1);
	return (j + i);
}

int		ft_type_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	if (g_plist.flags[1])
		return (ft_type_s_dot(str));
	if (g_plist.flags[0] == 2)
		while (i++ < g_plist.prec[0] - (int)ft_strlen(str))
			write(1, "0", 1);
	else if (g_plist.flags[0] == 4)
		while (i++ < g_plist.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	if (g_plist.flags[0] == 3)
	{
		while (i < g_plist.prec[0] && i < (int)ft_strlen(str))
			ft_putchar(str[i++]);
		return (i);
	}
	else
		ft_putstr(str);
	if (g_plist.flags[0] == 1)
		while (i++ < g_plist.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	return (ft_strlen(str) + (i ? --i : i));
}
