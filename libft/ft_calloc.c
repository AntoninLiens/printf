/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:52:39 by aliens            #+#    #+#             */
/*   Updated: 2020/11/22 17:27:52 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *dst;

	if (!(dst = malloc(sizeof(char) * (size * count))))
		return (NULL);
	ft_bzero(dst, (count * size));
	return (dst);
}
