/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:40:57 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:26:43 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_fill_0(int n)
{
	char *str;

	str = NULL;
	if (!(str = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	str[n] = '\0';
	while (--n >= 0)
		str[n] = '0';
	return (str);
}

char	*ft_fill(int n)
{
	char	*str;

	str = NULL;
	if (n <= 0)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	str[n] = '\0';
	while (--n >= 0)
		str[n] = ' ';
	return (str);
}
