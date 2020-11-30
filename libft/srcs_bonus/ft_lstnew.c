/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:17:05 by aliens            #+#    #+#             */
/*   Updated: 2020/11/27 11:59:39 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dst;

	if (!(dst = malloc(sizeof(t_list))))
		return (NULL);
	dst->content = content;
	dst->next = NULL;
	return (dst);
}
