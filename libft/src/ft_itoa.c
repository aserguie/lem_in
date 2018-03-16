/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:01:20 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:12 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char		*ft_itoa_neg(long n)
{
	char	*res;
	long	buf;
	int		len;

	len = 2;
	buf = n;
	while (buf >= 10)
	{
		buf /= 10;
		len++;
	}
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	len--;
	while (len > 0)
	{
		res[len] = 48 + n % 10;
		n /= 10;
		len--;
	}
	res[0] = '-';
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	long	buf;
	int		len;

	len = 1;
	buf = (long)n;
	if (n < 0)
		return (ft_itoa_neg(-buf));
	while (buf >= 10)
	{
		buf /= 10;
		len++;
	}
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = 48 + n % 10;
		n /= 10;
		len--;
	}
	return (res);
}
