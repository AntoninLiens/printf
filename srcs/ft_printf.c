/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:05:34 by aliens            #+#    #+#             */
/*   Updated: 2020/12/10 16:33:18 by aliens           ###   ########.fr       */
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
			sum += ft_flags(&format, arg);
		else
		{
			ft_putchar_fd(*format, 1);
			sum++;
		}
		format++;
	}
	va_end(arg);
	return (sum);
}
