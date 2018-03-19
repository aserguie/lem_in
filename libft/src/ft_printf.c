/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:09:34 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:29:25 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			ret;

	ret = 0;
	i = -1;
	va_start(ap, format);
	ret = ft_clone(ap, format, i, ret);
	va_end(ap);
	return (ret);
}
