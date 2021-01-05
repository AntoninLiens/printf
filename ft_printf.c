/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:05:34 by aliens            #+#    #+#             */
/*   Updated: 2021/01/05 19:22:14 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

void	ft_reset_list(void)
{
	t_list.flag_minus = 0;
	t_list.flag_zero = 0;
	t_list.flag_dot = 0;
	t_list.flag_star = 0;
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
			sum += ft_convert(&format, list.arg);
		else
		{
			ft_putchar_fd(*format, 1);
			sum++;
		}
		format++;
	}
	va_end(list.arg);
	return (sum);
}
