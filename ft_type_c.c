/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:43:09 by aliens            #+#    #+#             */
/*   Updated: 2021/01/19 14:37:18 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int	ft_type_c(int c)
{
	int	i;

	i = 0;
	if (list.flags[0] == 2)
		while (i++ < list.prec[0] - 1)
			write(1, "0", 1);
	else if (list.flags[0] == 4)
		while (i++ < list.prec[0] - 1)
			write(1, " ", 1);
	ft_putchar_fd(c, 1);
	if (list.flags[0] == 1)
		while (i++ < list.prec[0] - 1)
			write(1, " ", 1);
	return (i ? i : ++i);
}
