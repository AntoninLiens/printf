/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:34:17 by aliens            #+#    #+#             */
/*   Updated: 2020/12/04 15:59:32 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_convert_c(int c)
{
	char	c2;

	c2 = (char)c;
	ft_putchar_fd(c2, 1);
	return (1);
}
