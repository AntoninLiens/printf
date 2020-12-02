/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:32:15 by aliens            #+#    #+#             */
/*   Updated: 2020/12/02 15:28:52 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRINTF_H
# define PRINTF_H

#include <stdarg.h>

int	ft_printf(const char *format, ...);

int		ft_convert_c(int c);
int		ft_convert_d(int i);
int		ft_convert_s(char *str);
int		ft_convert_x(unsigned int n);

#endif
