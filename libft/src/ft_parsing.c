/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:27:55 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:28:57 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		parse_modif(const char *str, t_flags *fl)
{
	int i;
	int m;

	m = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
			m++;
		else
			break ;
		i++;
	}
	if (m > 0)
	{
		if (!(fl->modif = (char*)malloc(sizeof(char) * m + 1)))
			return (0);
		fl->modif[m] = '\0';
		while (--m >= 0)
			fl->modif[m] = str[m];
	}
	fl->conv = str[i];
	return (0);
}

static int		parse_pre(const char *format, t_flags *fl)
{
	int		i;

	i = 0;
	if (format[0] == '.')
	{
		fl->pre = ft_atoi(&format[1]);
		i++;
	}
	while (ft_isdigit(format[i]))
		i++;
	parse_modif(&format[i], fl);
	return (0);
}

static int		parse_field(const char *format, t_flags *fl)
{
	int		i;

	i = 0;
	fl->field = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		++i;
	parse_pre(&format[i], fl);
	return (0);
}

int				ft_parsing(const char *format, t_flags *fl)
{
	int		i;
	int		att;

	att = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '#' || format[i] == '0' || format[i] == '-' ||
			format[i] == '+' || format[i] == ' ')
			att++;
		else
			break ;
	}
	if (att > 0)
	{
		if (!(fl->attr = (char*)malloc(sizeof(char) * att + 1)))
			return (0);
		fl->attr[att] = '\0';
		while (--att >= 0)
			fl->attr[att] = format[att];
	}
	parse_field(&format[i], fl);
	return (0);
}
