/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:05:34 by aliens            #+#    #+#             */
/*   Updated: 2020/12/08 13:45:35 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		sum;

	sum = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_flags(&format, arg);
			sum += ft_convert(&format, arg);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			sum++;
		}
		format++;
	}
	return (sum);
}
