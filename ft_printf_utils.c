/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:55:36 by aliens            #+#    #+#             */
/*   Updated: 2021/01/21 14:40:33 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int	ft_p_atoi(const char *str)
{
	unsigned long long int	num2;
	unsigned long long int	num;
	int						i;
	int						sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num2 = num;
		num = num * 10 + (str[i] - '0');
		if (num >= LLONG_MAX || num < num2)
			return (sign == 1 ? -1 : 0);
		i++;
	}
	return (num * sign);
}

int	ft_p_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	if (!s || n < 0)
		return ;
	ptr = (char *)s;
	if (n == 0)
		return ;
	while (n--)
		ptr[n] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (!(dst = malloc(sizeof(char) * (size * count))))
		return (NULL);
	ft_bzero(dst, (count * size));
	return (dst);
}
