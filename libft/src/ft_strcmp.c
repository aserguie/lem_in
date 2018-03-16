/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:13:03 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:13 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	j = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (j);
}
