/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:05:34 by aliens            #+#    #+#             */
/*   Updated: 2021/01/06 17:22:40 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int		ft_check_type(const char **format)
{
	(*format)++;
	if (**format == 'c')
		return (ft_type_c(va_arg(list.arg, int)));
	else if (**format == 's')
		return (ft_type_s(va_arg(list.arg, char *)));
	else if (**format == 'p')
		return (ft_type_p(va_arg(list.arg, void *)));
	else if (**format == 'd' || **format == 'i')
		return (ft_type_d_i(va_arg(list.arg, int)));
	else if (**format == 'u')
		return (ft_type_u(va_arg(list.arg, int)));
	else if (**format == 'x')
		return (ft_type_lowerx(va_arg(list.arg, unsigned int)));
	else if (**format == 'X')
		return (ft_type_upperx(va_arg(list.arg, unsigned int)));
	else if (**format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

void	ft_check_flag(const char *format)
{
	int i;

	i = 0;
	if (format[i] == '-')
		list.flags[0] = 1;
	else if (format[i] == '0')
		list.flags[0] = 2;
	else if (format[i] == '.')
		list.flags[0] = 3;
	else if (format[i] == '*' || ft_isdigit((int)format[i]))
		list.flags[0] = 4;
	if (list.flags[0])
		i++;
	while (ft_isdigit((int)format[i]) ||
			(format[i] == '*' && format[i + 1] != '*'))
		i++;
	if (format[i] == '.' && list.flags[0] == 0)
		list.flags[1] = 4;
	return ;
}

void	ft_reset_list(void)
{
	list.flags[0] = 0;
	list.flags[1] = 0;
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
			ft_check_flag(format);
			sum += ft_check_type(&format);
		}
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
