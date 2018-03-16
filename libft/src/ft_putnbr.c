/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:35:25 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:13 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr(int n)
{
	long buffer;

	buffer = n;
	if (buffer < 0)
	{
		ft_putchar('-');
		buffer *= -1;
	}
	if (buffer < 10)
		ft_putchar(buffer + '0');
	else
	{
		ft_putnbr(buffer / 10);
		ft_putnbr(buffer % 10);
	}
}
