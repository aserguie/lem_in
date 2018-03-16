/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:57:14 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:15 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)big;
	j = 0;
	i = 0;
	if (little[0] == '\0')
		return (str);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			while ((big[i + j] != '\0') && (big[i + j] == little[j])
					&& (i + j <= len))
				j++;
			if (little[j] == '\0')
				return (&str[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
