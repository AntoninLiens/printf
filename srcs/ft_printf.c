/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:05:34 by aliens            #+#    #+#             */
/*   Updated: 2020/12/03 16:44:44 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_convert(char c, va_list)
{
	if (c == 'c')
		return (ft_convert_c(va_arg(char)));
	else if (c == 's')
		return (ft_convert_s(va_arg(char *)));
	else if (c == 'p')
		return (ft_convert_p(va_arg(void *)));
	else if (c == 'd' || c == 'i')
		return (ft_convert_d_i(va_arg(int)));
	else if (c == 'u')
		return (ft_convert_u(va_arg(int)));
	else if (c == 'x')
		return (ft_convert_lowerx(va_arg(unsigned int)));
	else if (c == 'X')
		return (ft_convert_upperX(va_arg(unsigned int)));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	i;
	int	sum;

	i = -1;
	sum = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			sum += ft_convert(format[i + 1], va_list);
		while (format[i] != '%')
		{
			i++;
			sum++;
		}
	}
	return (0);
}
