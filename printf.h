/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:32:15 by aliens            #+#    #+#             */
/*   Updated: 2021/01/18 15:18:29 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_ft_printf
{
	va_list		arg;
	int			flags[2];
	int			prec[2];
}				p_list;

p_list			list;

void			ft_reset_list(void);

int				ft_printf(const char *format, ...);

int				ft_get_type(const char **format);
void			ft_get_flag(const char **format);
void			ft_get_prec(const char **format, int i);

int				ft_type_c(int c);
int				ft_type_d_i(int i);
int				ft_type_s(char *str);
int				ft_type_x(unsigned int n, char *base);
int				ft_type_p(void *ptr);
int				ft_type_u(int n);

#endif
