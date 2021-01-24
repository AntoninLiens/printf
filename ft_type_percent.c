/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:34:21 by aliens            #+#    #+#             */
/*   Updated: 2021/01/24 15:44:30 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int		ft_type_percent(void)
{
	int	i;

	i = -1;
	if (list.flags[0] == 2)
		while(++i < list.prec[0] - 1)
			write(1, "0", 1);
	else if (list.flags[0] == 3)
		i++;
	else if (list.flags[0] == 4)
		while (++i < list.prec[0] - 1)
			write(1, " ", 1);
	ft_putchar('%');
	if (list.flags[0] == 1)
		while (++i < list.prec[0] - 1)
			write(1, " ", 1);
	return (1 + (i ? i : i++));
}
