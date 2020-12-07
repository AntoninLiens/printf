/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:22:25 by aliens            #+#    #+#             */
/*   Updated: 2020/12/07 14:49:08 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main(void)
{
	void *ptr;

	if (!(ptr = ft_calloc(sizeof(char), 11)))
		return (0);
	printf("%d\n", 11);
	ft_printf("%d\n", 11);
	printf("%c\n", 'a');
	ft_printf("%c\n", 'a');
	printf("%s\n", "salut les amis");
	ft_printf("%s\n", "salut les amis");
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);
	printf("%x\n", 42);
	ft_printf("%x\n", 42);
	printf("%X\n", 19);
	ft_printf("%X\n", 19);
	printf("%%\n");
	ft_printf("%%\n");
	printf("aliens c moa\n");
	ft_printf("aliens c moa\n");
	return (0);
}
