/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:04:31 by aliens            #+#    #+#             */
/*   Updated: 2020/12/08 14:50:26 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_flags(const char **format, va_list arg)
{
	*format++;
	if (**format == '-')
		return (ft_flag_minus(&format, va_arg(arg, int)));
	else if (**format == '0' || **format == '.')
		return (ft_flags_zero_point(&format, va_arg(arg, int)));
	else if (**format == '*')
		return (ft_flag_all(&format, va_arg(arg, int)));
	return (ft_convert(format, arg);
}		
