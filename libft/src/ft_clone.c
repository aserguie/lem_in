/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:16:23 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:26:18 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_flags		ft_init_flags(void)
{
	t_flags	fl;

	fl.field = 0;
	fl.pre = -1;
	fl.conv = 0;
	fl.count = 0;
	fl.attr = NULL;
	fl.modif = NULL;
	return (fl);
}

int			ft_clone(va_list ap, const char *format, int i, int ret)
{
	t_flags		fl;

	while (format[++i] != '\0')
	{
		fl = ft_init_flags();
		if (format[i] == '%')
		{
			i++;
			ft_parsing(&format[i], &fl);
			i += ft_strnlen(&format[i], fl.conv);
			ft_putarg(ap, &fl);
			if (fl.attr)
				ft_strdel(&fl.attr);
			if (fl.modif)
				ft_strdel(&fl.modif);
		}
		else
		{
			ft_putchar(format[i]);
			ret++;
		}
		ret += fl.count;
	}
	return (ret);
}
