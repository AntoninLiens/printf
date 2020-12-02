/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:05:34 by aliens            #+#    #+#             */
/*   Updated: 2020/12/02 13:29:57 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	i;

	i = -1;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			ft_convert(format[i + 1]);
		while (format[i] != '%')
			i++;
	}
	return (0);
}
