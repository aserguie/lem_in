/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:08:33 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:26:28 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		ft_char(char c, t_flags *fl)
{
	if (fl->field == 0)
	{
		ft_putchar(c);
		fl->count++;
		return (0);
	}
	fl->count += fl->field;
	if (!(fl->attr))
	{
		while (fl->field > 1)
		{
			ft_putchar(' ');
			fl->field--;
		}
		ft_putchar(c);
		return (0);
	}
	ft_putchar(c);
	while (fl->field > 1)
	{
		ft_putchar(' ');
		fl->field--;
	}
	return (0);
}

static int		ft_mod_c(va_list ap, t_flags *fl)
{
	char	c;

	if (ft_strchr(fl->modif, 'l') || fl->conv == 'C')
		c = (char)va_arg(ap, wchar_t);
	else
	{
		c = va_arg(ap, int);
		ft_char(c, fl);
	}
	return (0);
}

static int		ft_mod_s(va_list ap, t_flags *fl)
{
	char	*str;
	int		a;

	if (ft_strchr(fl->modif, 'l') || fl->conv == 'S')
		str = (char*)va_arg(ap, wchar_t*);
	else
	{
		str = va_arg(ap, char*);
		if (str == NULL)
		{
			ft_putstr("(null)");
			fl->count += 6;
			return (0);
		}
		a = ft_strlen(str);
		ft_string(str, fl, a);
	}
	return (0);
}

int				ft_conv(va_list ap, t_flags *fl)
{
	if (fl->conv == 's' || fl->conv == 'S')
		ft_mod_s(ap, fl);
	else if (fl->conv == 'c' || fl->conv == 'C')
		ft_mod_c(ap, fl);
	else if (fl->conv == 'p')
		ft_pointer(ap, fl);
	else if (fl->conv == 'O' || fl->conv == 'o' || fl->conv == 'u' ||
			fl->conv == 'U' || fl->conv == 'x' || fl->conv == 'X')
		ft_mod_uns(ap, fl);
	else if (fl->conv == 'd' || fl->conv == 'i')
		ft_mod_id(ap, fl);
	else if (fl->conv == 'D')
		ft_mod_id2(ap, fl);
	else if (fl->conv == '%')
		ft_percent(fl);
	return (0);
}
