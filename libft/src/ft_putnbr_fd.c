/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:21:09 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:13 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long buffer;

	buffer = n;
	if (buffer < 0)
	{
		ft_putchar_fd('-', fd);
		buffer *= -1;
	}
	if (buffer < 10)
		ft_putchar_fd(buffer + '0', fd);
	else
	{
		ft_putnbr_fd(buffer / 10, fd);
		ft_putnbr_fd(buffer % 10, fd);
	}
}
