/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:27:16 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:29:15 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int		ft_pointbis(char *str, t_flags *f, int a)
{
	if (f->field > a + 2)
	{
		f->count += f->field;
		while (f->field > a + 2)
		{
			ft_putchar(' ');
			f->field--;
		}
		ft_putstr("0x");
		ft_putstr(str);
		return (0);
	}
	f->count += a + 2;
	ft_putstr("0x");
	ft_putstr(str);
	ft_strdel(&str);
	return (0);
}

static	int		ft_pointflag(char *str, t_flags *f, int a)
{
	if (f->field > a + 2)
	{
		f->count += f->field;
		ft_putstr("0x");
		ft_putstr(str);
		while (f->field > a + 2)
		{
			ft_putchar(' ');
			f->field--;
		}
		return (0);
	}
	f->count += a + 2;
	ft_putstr("0x");
	ft_putstr(str);
	ft_strdel(&str);
	return (0);
}

int				ft_pointer(va_list ap, t_flags *fl)
{
	void	*p;
	size_t	i;
	char	*str;
	int		a;

	a = 0;
	str = NULL;
	p = va_arg(ap, void*);
	i = (size_t)p;
	str = ft_itoa_base(i, 16);
	a = ft_strlen(str);
	if (ft_strchr(fl->attr, '-'))
		ft_pointflag(str, fl, a);
	else
		ft_pointbis(str, fl, a);
	return (0);
}
