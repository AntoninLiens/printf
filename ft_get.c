/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:14:53 by aliens            #+#    #+#             */
/*   Updated: 2021/01/29 17:14:28 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int		ft_get_type(const char **format)
{
	if (**format == 0)
		list.error = 1;
	else if (**format == 'c')
		return (ft_type_c(va_arg(list.arg, int)));
	else if (**format == 's')
		return (ft_type_s(va_arg(list.arg, char *)));
	else if (**format == 'p')
		return (ft_type_p(va_arg(list.arg, void *), "0123456789abcdef"));
	else if (**format == 'd' || **format == 'i')
		return (ft_type_d_i(va_arg(list.arg, int), 0));
	else if (**format == 'u')
		return (ft_type_u(va_arg(list.arg, int)));
	else if (**format == 'x')
		return (ft_type_x(va_arg(list.arg, unsigned int), 0,
					"0123456789abcdef"));
	else if (**format == 'X')
		return (ft_type_x(va_arg(list.arg, unsigned int), 0,
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
			list.flags[i] = 1;
		else if (**format == '0')
			list.flags[i] = 2;
		else if (**format == '.')
			list.flags[i] = 3;
		else if (**format == '*' || ft_p_isdigit((int)**format))
			list.flags[i] = 4;
		if (list.flags[i])
		{
			if (list.flags[i] != 4)
				(*format)++;
			list.prec[i] = ft_p_atoi(format, 1);
		}
	}
	return ;
}
