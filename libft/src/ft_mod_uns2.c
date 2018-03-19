/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_uns2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:13:39 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:28:32 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int		ft_getarg_unli(va_list ap, t_flags *f)
{
	unsigned	long	int	i;
	char					*str;

	i = (unsigned long int)va_arg(ap, unsigned long int);
	if (i == 0 && (f->pre > -1 || f->field > 0))
	{
		ft_zero(f);
		return (0);
	}
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(i, 8);
	else if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(i, 16);
	else
		str = ft_itoa_base(i, 10);
	if (f->conv == 'X')
		ft_upper(str);
	ft_attr_ux(str, f);
	return (0);
}

static	int		ft_getarg_size(va_list ap, t_flags *f)
{
	size_t	i;
	char	*str;

	i = va_arg(ap, size_t);
	if (i == 0 && (f->pre > -1 || f->field > 0))
	{
		ft_zero(f);
		return (0);
	}
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(i, 8);
	else if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(i, 16);
	else
		str = ft_itoa_base(i, 10);
	if (f->conv == 'X')
		ft_upper(str);
	ft_attr_ux(str, f);
	return (0);
}

static	int		ft_getarg_uint(va_list ap, t_flags *f)
{
	uintmax_t	i;
	char		*str;

	i = va_arg(ap, uintmax_t);
	if (i == 0 && (f->pre > -1 || f->field > 0))
	{
		ft_zero(f);
		return (0);
	}
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(i, 8);
	else if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(i, 16);
	else
		str = ft_itoa_base(i, 10);
	if (f->conv == 'X')
		ft_upper(str);
	ft_attr_ux(str, f);
	return (0);
}

int				ft_mod_uns2(va_list ap, t_flags *fl)
{
	if (fl->modif[0] == 'l')
		ft_getarg_unli(ap, fl);
	else if (fl->modif[0] == 'j')
		ft_getarg_uint(ap, fl);
	else if (fl->modif[0] == 'z')
		ft_getarg_size(ap, fl);
	return (0);
}
