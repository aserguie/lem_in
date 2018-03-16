/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:21:43 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:12 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dst;

	if (n <= 0)
		return (0);
	i = 0;
	src = (unsigned char*)s1;
	dst = (unsigned char*)s2;
	while (src[i] == dst[i] && i < n - 1)
		i++;
	return (src[i] - dst[i]);
}
