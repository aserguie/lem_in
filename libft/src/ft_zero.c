/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:58:17 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:30:43 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	void	ft_zeroplus(t_flags *f)
{
	if (f->field > f->pre)
	{
		f->count = f->count + f->field;
		while (f->field > f->pre)
		{
			ft_putchar(' ');
			f->field--;
		}
		while (f->pre > 0)
		{
			ft_putchar('0');
			f->pre--;
		}
	}
	if (f->pre > f->field)
	{
		f->count = f->count + f->field;
		while (f->pre > 0)
		{
			ft_putchar('0');
			f->pre--;
		}
	}
}

int				ft_zero(t_flags *fl)
{
	if (fl->pre == 0 && fl->field == 0)
		if (ft_strchr(fl->attr, '#') && fl->conv == 'o')
		{
			ft_putchar(48);
			fl->count++;
			return (0);
		}
	if (fl->pre > 0)
		ft_zeroplus(fl);
	else if (fl->field > 0)
	{
		fl->count = fl->count + fl->field;
		while (fl->field > 0)
		{
			ft_putchar(' ');
			fl->field--;
		}
	}
	return (0);
}
