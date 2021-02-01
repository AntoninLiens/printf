/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:01:22 by aliens            #+#    #+#             */
/*   Updated: 2021/02/01 13:51:10 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_ten_size(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_ten_size(n / 10));
}

int		ft_hex_size(unsigned long n)
{
	if (n < 16)
		return (1);
	return (1 + ft_hex_size(n / 16));
}
