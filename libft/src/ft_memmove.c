/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:43:39 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:12 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char*)src;
	d = (char*)dst;
	i = 0;
	if (d > s && s + len > d)
	{
		len--;
		while (len > 0)
		{
			d[len] = s[len];
			len--;
		}
		d[len] = s[len];
	}
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
