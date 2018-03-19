/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:06:31 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:41:47 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned	char	o;
	int					i;

	i = 0;
	o = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != o)
		i++;
	if (o == '\0')
		return ((char*)s + i);
	if (s[i] == '\0')
		return (NULL);
	return ((char*)s + i);
}
