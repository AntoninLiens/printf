/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:54:25 by aliens            #+#    #+#             */
/*   Updated: 2020/12/10 16:36:17 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_convert(const char **format, va_list arg)
{
	if (**format == 'c')
		return (ft_convert_c(va_arg(arg, int)));
	else if (**format == 's')
		return (ft_convert_s(va_arg(arg, char *)));
	else if (**format == 'p')
		return (ft_convert_p(va_arg(arg, void *)));
	else if (**format == 'd' || **format == 'i')
		return (ft_convert_d_i(va_arg(arg, int)));
	else if (**format == 'u')
		return (ft_convert_u(va_arg(arg, int)));
	else if (**format == 'x')
		return (ft_convert_lowerx(va_arg(arg, unsigned int)));
	else if (**format == 'X')
		return (ft_convert_upperx(va_arg(arg, unsigned int)));
	else if (**format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
