/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:06:48 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:42:23 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (!str || (!s1 && !s2))
		return (NULL);
	if (s1)
		str = ft_strncpy(str, s1, ft_strlen(s1));
	if (s2)
		str = ft_strncat(str, s2, ft_strlen(s2));
	return (str);
}
