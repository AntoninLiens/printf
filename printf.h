/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:32:15 by aliens            #+#    #+#             */
/*   Updated: 2021/01/05 19:21:47 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_list
{
	va_list	arg;
	int		flag_minus;
	int		flag_zero;
	int		flag_dot;
	int		flag_star;
}				t_list;

t_list			list;

int				ft_printf(const char *format, ...);

int				ft_convert(const char **format, va_list arg);

int				ft_convert_c(int c);
int				ft_convert_d_i(int i);
int				ft_convert_s(char *str);
int				ft_convert_lowerx(unsigned int n);
int				ft_convert_upperx(unsigned int n);
int				ft_convert_p(void *ptr);
int				ft_convert_u(int n);

int				ft_flags(const char **format, va_list arg);

#endif
