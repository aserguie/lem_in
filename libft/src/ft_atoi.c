/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:21:48 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:11 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	res = 0;
	sign = 1;
	while (((9 <= str[i]) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
