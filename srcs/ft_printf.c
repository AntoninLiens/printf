/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:05:34 by aliens            #+#    #+#             */
/*   Updated: 2020/12/04 15:56:07 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	i;
	int		sum;

	i = -1;
	sum = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			sum += ft_convert(format[++i], arg);
		else
		{
			ft_putchar_fd(format[i], 1);
			sum++;
		}
		i++;
	}
	return (sum);
}
