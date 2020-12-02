/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:52:43 by aliens            #+#    #+#             */
/*   Updated: 2020/12/01 17:56:36 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*dst;

	if (!lst)
		return (NULL);
	if (!f)
		return (lst);
	dst = NULL;
	while (lst)
	{
		if (!(lst2 = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&dst, lst2);
		lst = lst->next;
	}
	return (dst);
}
