/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:32:15 by aliens            #+#    #+#             */
/*   Updated: 2020/12/07 16:13:17 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);

int		ft_convert(char c, va_list arg);

int		ft_convert_c(int c);
int		ft_convert_d_i(int i);
int		ft_convert_s(char *str);
int		ft_convert_lowerx(unsigned int n);
int		ft_convert_upperx(unsigned int n);
int		ft_convert_p(void *ptr);
int		ft_convert_u(int n);

#endif
