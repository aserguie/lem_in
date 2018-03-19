/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:00:53 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:29:08 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int		ft_perce(t_flags *f)
{
	f->count = f->count + f->field;
	if (!(f->attr))
	{
		while (f->field > 1)
		{
			ft_putchar(' ');
			f->field--;
		}
		ft_putchar('%');
	}
	else if (ft_strchr(f->attr, '-'))
	{
		ft_putchar('%');
		while (f->field > 1)
		{
			ft_putchar(' ');
			f->field--;
		}
	}
	return (0);
}

int				ft_percent(t_flags *fl)
{
	if (fl->field == 0)
	{
		ft_putchar('%');
		fl->count++;
		return (0);
	}
	else
		ft_perce(fl);
	return (0);
}
