/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:43:09 by aliens            #+#    #+#             */
/*   Updated: 2021/02/01 13:51:43 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int	ft_type_c(int c)
{
	int	i;

	i = 0;
	if (g_plist.flags[0] == 2)
		while (i++ < g_plist.prec[0] - 1)
			write(1, "0", 1);
	else if (g_plist.flags[0] == 4)
		while (i++ < g_plist.prec[0] - 1)
			write(1, " ", 1);
	ft_putchar(c);
	if (g_plist.flags[0] == 1)
		while (i++ < g_plist.prec[0] - 1)
			write(1, " ", 1);
	return (i ? i : ++i);
}
