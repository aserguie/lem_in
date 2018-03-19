/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_id2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:13:27 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:28:04 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int		ft_getarg_li(va_list ap, t_flags *f)
{
	long	int	i;
	char		*str;

	i = va_arg(ap, long int);
	if (i == 0 && (f->pre > -1 || f->field > 0) && (!(f->attr)))
	{
		ft_zero(f);
		return (0);
	}
	if (i < 0)
	{
		i = i * -1;
		str = ft_itoa_base(i, 10);
		ft_nega(str, f);
		return (0);
	}
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

static	int		ft_getarg_size(va_list ap, t_flags *f)
{
	size_t	i;
	char	*str;
	char	c;

	c = 0;
	i = va_arg(ap, size_t);
	if (i == 0 && (f->pre > -1 || f->field > 0) && (!(f->attr)))
	{
		ft_zero(f);
		return (0);
	}
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

static	int		ft_getarg_intmax(va_list ap, t_flags *f)
{
	intmax_t	i;
	char		*str;

	i = va_arg(ap, intmax_t);
	if (i == 0 && (f->pre > -1 || f->field > 0) && (!(f->attr)))
	{
		ft_zero(f);
		return (0);
	}
	if (i < 0)
	{
		i = i * -1;
		str = ft_itoa_base(i, 10);
		ft_nega(str, f);
		return (0);
	}
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

int				ft_mod_id2(va_list ap, t_flags *fl)
{
	if (fl->conv == 'D')
		ft_getarg_li(ap, fl);
	else if (fl->modif[0] == 'l')
		ft_getarg_li(ap, fl);
	else if (fl->modif[0] == 'j')
		ft_getarg_intmax(ap, fl);
	else if (fl->modif[0] == 'z')
		ft_getarg_size(ap, fl);
	return (0);
}
