/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:32:15 by aliens            #+#    #+#             */
/*   Updated: 2021/01/29 17:12:36 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_ft_printf
{
	va_list		arg;
	int			flags[2];
	int			prec[2];
	int			error;
}				p_list;

p_list			list;

void			ft_reset_list(void);

int				ft_printf(const char *format, ...);

int				ft_get_type(const char **format);
void			ft_get_flag(const char **format);
void			ft_get_prec(const char **format, int i);
void			ft_ajust(void);

int				ft_type_c(int c);
int				ft_type_d_i(int i, int neg);
int				ft_type_s(char *str);
int				ft_type_x(unsigned int n, int i, char *base);
int				ft_type_p(void *ptr, char *hex);
int				ft_type_u(int n);
int				ft_type_percent(void);

int				ft_p_atoi(const char **str, int sign);
int				ft_p_isdigit(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);

void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnbr_ui(unsigned int n);

size_t			ft_strlen(const char *str);
int				ft_ten_size(unsigned int n);
int				ft_hex_size(unsigned long n);

#endif
