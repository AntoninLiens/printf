/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:29:58 by aliens            #+#    #+#             */
/*   Updated: 2020/11/23 14:20:02 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*ptrsrc;
	char		*ptrdst;

	ptrdst = (char *)dst;
	ptrsrc = (const char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n--)
		ptrdst[n] = ptrsrc[n];
	return (dst);
}
