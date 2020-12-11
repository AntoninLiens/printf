/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:27:32 by aliens            #+#    #+#             */
/*   Updated: 2020/12/10 17:06:11 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_size(unsigned int s)
{
	int i;

	i = 0;
	while (s > 9)
	{
		s /= 10;
		i++;
	}
	return (i);
}

int		ft_flag_minus(const char **format, va_list arg)
{
	int		s;
	int		ret;

	s = 0;
	ret = 0;
	(*format)++;
	if (**format == '*')
	{
		s = va_arg(arg, int);
		(*format)++;
	}
	else if (ft_isdigit((int)**format))
	{
		s = ft_atoi((const char *)*format);
		while (ret++ < ft_size(s))
			(*format)++;
		ret = 0;
	}
	ret += ft_convert(format, arg);
	while (++ret < s)
		ft_putchar_fd(' ', 1);
	return (ret);
}
