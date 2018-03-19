/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:05:55 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:37:52 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_itoa_base(size_t n, int base)
{
	int			a;
	size_t		b;
	char		*str;

	a = 2;
	b = n;
	while ((b /= base) >= 1)
		a++;
	if (!(str = (char*)malloc(sizeof(char) * a)))
		return (NULL);
	a--;
	str[a] = '\0';
	while (--a >= 0)
	{
		b = 48;
		if (n % base > 9)
			b = 87;
		str[a] = n % base + b;
		n = n / base;
	}
	return (str);
}
