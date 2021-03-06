/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:26 by aliens            #+#    #+#             */
/*   Updated: 2021/02/25 16:02:26 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_get_type(const char **format)
{
	if (**format == 0)
		g_plist.error = 1;
	else if (**format == 'c')
		return (ft_type_c(va_arg(g_plist.arg, int)));
	else if (**format == 's')
		return (ft_type_s(va_arg(g_plist.arg, char *)));
	else if (**format == 'p')
		return (ft_type_p(va_arg(g_plist.arg, void *), "0123456789abcdef"));
	else if (**format == 'd' || **format == 'i')
		return (ft_type_d_i(va_arg(g_plist.arg, int), 0));
	else if (**format == 'u')
		return (ft_type_u(va_arg(g_plist.arg, int)));
	else if (**format == 'x')
		return (ft_type_x(va_arg(g_plist.arg, unsigned int), 0,
					"0123456789abcdef"));
	else if (**format == 'X')
		return (ft_type_x(va_arg(g_plist.arg, unsigned int), 0,
					"0123456789ABCDEF"));
	else if (**format == '%')
		return (ft_type_c((int)'%'));
	return (0);
}

void	ft_get_flag(const char **format)
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		if (**format == '-')
			g_plist.flags[i] = 1;
		else if (**format == '0')
			g_plist.flags[i] = 2;
		else if (**format == '.')
			g_plist.flags[i] = 3;
		else if (**format == '*' || ft_p_isdigit((int)**format))
			g_plist.flags[i] = 4;
		if (g_plist.flags[i])
		{
			if (g_plist.flags[i] != 4)
				(*format)++;
			g_plist.prec[i] = ft_p_atoi(format, 1);
		}
	}
	return ;
}
