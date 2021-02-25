/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:37:10 by aliens            #+#    #+#             */
/*   Updated: 2021/02/25 14:55:31 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr_ui(unsigned int n)
{
	if (n > 9)
		ft_putnbr_ui(n / 10);
	ft_putchar('0' + n % 10);
}
