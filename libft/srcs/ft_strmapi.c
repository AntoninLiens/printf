/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:05:32 by aliens            #+#    #+#             */
/*   Updated: 2020/11/26 13:47:17 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	i = -1;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[++i])
		dst[i] = f(i, s[i]);
	dst[i] = 0;
	return (dst);
}
