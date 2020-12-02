/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:13:44 by aliens            #+#    #+#             */
/*   Updated: 2020/12/01 17:53:16 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst2;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lst2 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst2;
	}
}
