/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:29:55 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:49:45 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*src;

	src = s;
	i = 0;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
}
