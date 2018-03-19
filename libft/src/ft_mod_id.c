/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:13:17 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:27:39 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int		ft_getarg_lli(va_list ap, t_flags *f)
{
	long	long	int	i;
	char				*str;

	i = va_arg(ap, long long int);
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

static	int		ft_getarg_shi(va_list ap, t_flags *f)
{
	short	int	i;
	char		*str;

	i = (short int)va_arg(ap, int);
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
	}
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

static	int		ft_getarg_char(va_list ap, t_flags *f)
{
	signed	char	i;
	char			*str;

	i = (signed char)va_arg(ap, int);
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

static	int		ft_getarg_int(va_list ap, t_flags *f)
{
	ssize_t		i;
	char		*str;

	i = va_arg(ap, int);
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

int				ft_mod_id(va_list ap, t_flags *fl)
{
	if (!(fl->modif))
		ft_getarg_int(ap, fl);
	else if (fl->modif[0] == 'h' && fl->modif[1] == 'h')
		ft_getarg_char(ap, fl);
	else if (fl->modif[0] == 'h')
		ft_getarg_shi(ap, fl);
	else if (fl->modif[0] == 'l' && fl->modif[1] == 'l')
		ft_getarg_lli(ap, fl);
	else
		ft_mod_id2(ap, fl);
	return (0);
}
