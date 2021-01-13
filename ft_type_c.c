/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:43:09 by aliens            #+#    #+#             */
/*   Updated: 2021/01/13 15:15:16 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int	ft_type_c(int c)
{
	int	i;

	i = -1;
	if (list.flags[0] == 3 && list.prec[0])
		return (-1);
	if (list.flags[1] == 3 && list.prec[1])
		return (-1);
	if (list.flags[0] == 4)
	{
		while (++i < list.prec[0] - 1)
			write(1, " ", 1);
	}
	ft_putchar_fd((char)c, 1);
	if (list.flags[0] == 1)
	{
		if (!list.prec[0])
			return (1);
		while (++i < list.prec[0] - 1)
			write(1, " ", 1);
	}
	return (list.prec[0]);
}
