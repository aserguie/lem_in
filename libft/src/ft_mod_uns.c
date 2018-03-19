/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:13:34 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:28:21 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int		ft_getarg_unlli(va_list ap, t_flags *f)
{
	unsigned	long	long	int	i;
	char							*str;

	i = va_arg(ap, unsigned long long int);
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

static	int		ft_getarg_unshi(va_list ap, t_flags *f)
{
	unsigned	short	int	i;
	char					*str;

	i = (unsigned short int)va_arg(ap, unsigned int);
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

static	int		ft_getarg_unchar(va_list ap, t_flags *f)
{
	unsigned	char	i;
	char				*str;

	i = (unsigned char)va_arg(ap, unsigned int);
	if (i == 0 && (f->pre > -1 || f->field > 0))
	{
		ft_zero(f);
		return (0);
	}
	if (i == 0)
	{
		ft_putchar(48);
		f->count++;
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

static	int		ft_getarg_unint(va_list ap, t_flags *f)
{
	unsigned	int	i;
	char			*str;

	i = va_arg(ap, unsigned int);
	if (i == 0 && (f->pre > -1 || f->field > 0))
	{
		ft_zero(f);
		return (0);
	}
	if (i == 0)
	{
		ft_putchar(48);
		f->count++;
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

int				ft_mod_uns(va_list ap, t_flags *fl)
{
	if (!(fl->modif))
		ft_getarg_unint(ap, fl);
	else if (fl->modif[0] == 'h' && fl->modif[1] == 'h')
		ft_getarg_unchar(ap, fl);
	else if (fl->modif[0] == 'h')
		ft_getarg_unshi(ap, fl);
	else if (fl->modif[0] == 'l' && fl->modif[1] == 'l')
		ft_getarg_unlli(ap, fl);
	else
		ft_mod_uns2(ap, fl);
	return (0);
}
