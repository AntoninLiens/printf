/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:01:22 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 14:43:05 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

size_t	ft_p_strlen(const char *str)
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

int		ft_sixteen_size(unsigned long n)
{
	if (n < 16)
		return (1);
	return (1 + ft_sixteen_size(n / 16));
}
