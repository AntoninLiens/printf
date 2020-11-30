/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:32:53 by aliens            #+#    #+#             */
/*   Updated: 2020/11/21 11:11:10 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	i = ft_strlen((char *)s);
	while (i--)
		if (s[i] == c)
			return ((char *)s + i);
	return (0);
}
