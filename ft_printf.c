/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:05:34 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 14:06:42 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

void	ft_reset_list(void)
{
	list.flags[0] = 0;
	list.flags[1] = 0;
	list.prec[0] = 0;
	list.prec[1] = 0;
}

int		ft_printf(const char *format, ...)
{
	int		sum;

	sum = 0;
	va_start(list.arg, format);
	ft_reset_list();
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_get_flag(&format);
			sum += ft_get_type(&format);
		}
		else
		{
			ft_putchar(*format);
			sum++;
		}
		format++;
	}
	va_end(list.arg);
	return (sum);
}
