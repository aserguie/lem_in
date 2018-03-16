/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:51:18 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:15 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	str = (char *)big;
	if (little[0] == '\0')
		return (str);
	while (big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while ((big[i + j] != '\0') && (big[i + j] == little[j]))
				j++;
			if (little[j] == '\0')
				return (str + i);
			j = 0;
		}
		i++;
	}
	return (0);
}
