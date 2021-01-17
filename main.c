/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:22:25 by aliens            #+#    #+#             */
/*   Updated: 2021/01/17 16:13:23 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main(void)
{
//	void *ptr;

//	if (!(ptr = ft_calloc(sizeof(char), 11)))
//		return (0);
/*	ft_printf("printf d : %d\n", printf("%d\n", 0));
	ft_printf("ft_printf d : %d\n", ft_printf("%d\n", 0));
	ft_printf("printf c : %d\n", printf("%c\n", 'a'));
	ft_printf("ft_printf c : %d\n", ft_printf("%c\n", 'a'));
	ft_printf("printf s : %d\n", printf("%s\n", "salut les amis"));
	ft_printf("ft_printf s : %d\n", ft_printf("%s\n", "salut les amis"));
	ft_printf("printf p : %d\n", printf("%p\n", ptr));
	ft_printf("ft_printf p : %d\n", ft_printf("%p\n", ptr));
	ft_printf("printf x : %d\n", printf("%x\n", 42));
	ft_printf("ft_printf p : %d\n", ft_printf("%x\n", 42));
	ft_printf("printf X : %d\n", printf("%X\n", 19));
	ft_printf("ft_printf X : %d\n", ft_printf("%X\n", 19));
	ft_printf("printf % : %d\n", printf("%%\n"));
	ft_printf("ft_printf % : %d\n", ft_printf("%%\n"));
	ft_printf("printf : %d\n", printf("aliens c moa\n"));
	ft_printf("ft_printf : %d\n", ft_printf("aliens c moa\n"));
	ft_printf("printf u : %d\n", printf("%u\n", 10));
	ft_printf("ft_printf u : %d\n", ft_printf("%u\n", 10));
	ft_printf("printf u : %d\n", printf("%u\n", -10));
	ft_printf("ft_printf u : %d\n", ft_printf("%u\n", -10));
	ft_printf("%---------12.*d\n", 19, 42);
	printf("flags actifs :\n");
	printf("1 : %d\n", list.flags[0]);
	printf("2 : %d\n", list.flags[1]);
	printf("precision :\n");
	printf("1 : %d\n", list.prec[0]);
	printf("2 : %d\n", list.prec[1]);*/
//	ft_printf("%d\n", ft_printf("%-10p|\n", ptr));
	printf("%d\n", ft_printf("%-5.i|\n", 19));
	printf("%d\n", printf("%-5.i|\n", 19));
//	free(ptr);
	return (0);
}
