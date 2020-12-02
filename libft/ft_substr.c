/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:25:06 by aliens            #+#    #+#             */
/*   Updated: 2020/11/26 12:48:11 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!(dst = ft_calloc(sizeof(char), len + 1)) || !s)
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i])
		if (i >= start && ++j < len)
			dst[j] = s[i];
	return (dst);
}
