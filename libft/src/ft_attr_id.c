/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attr_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:47:44 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:25:01 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	void	ft_putstrattr(char *str, t_flags *f)
{
	ft_putstr(str);
	f->count = ft_strlen(str);
	ft_strdel(&str);
}

static	char	*ft_is_zero(char *str, t_flags *f)
{
	int		i;

	i = 0;
	if (f->pre != -1)
		return (str);
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

static	char	*ft_is_plus(char *str, t_flags *f, int a)
{
	char	*temp;
	int		i;

	i = 0;
	if (f->pre >= f->field)
	{
		temp = ft_strjoin("+", str);
		ft_strdel(&str);
		return (temp);
	}
	if (ft_strchr(f->attr, '0'))
		str = ft_is_zero(str, f);
	while (str[i] == ' ')
		i++;
	if (i != 0)
		str[i - 1] = '+';
	else if (f->field > a)
		str[i] = '+';
	else
	{
		temp = ft_strjoin("+", str);
		ft_strdel(&str);
		return (temp);
	}
	return (str);
}

static	char	*ft_is_space(char *str, t_flags *f, int a)
{
	char	*space;

	if (f->pre >= f->field)
	{
		space = ft_strjoin(" ", str);
		ft_strdel(&str);
		return (space);
	}
	if (ft_strchr(f->attr, '0'))
		str = ft_is_zero(str, f);
	if (f->field > a)
		str[0] = ' ';
	else
	{
		space = ft_strjoin(" ", str);
		ft_strdel(&str);
		return (space);
	}
	return (str);
}

int				ft_attr_id(char *str, t_flags *fl)
{
	char	*finish;
	char	*strattr;
	int		a;

	a = ft_strlen(str);
	strattr = NULL;
	finish = ft_is_pre(str, fl);
	if (!(fl->attr))
	{
		ft_putstr(finish);
		fl->count = ft_strlen(finish);
		ft_strdel(&finish);
		return (0);
	}
	else if (ft_strchr(fl->attr, '-'))
		strattr = ft_min(finish, fl, a);
	else if (ft_strchr(fl->attr, '+'))
		strattr = ft_is_plus(finish, fl, a);
	else if (ft_strchr(fl->attr, ' '))
		strattr = ft_is_space(finish, fl, a);
	else if (ft_strchr(fl->attr, '0'))
		strattr = ft_is_zero(finish, fl);
	ft_putstrattr(strattr, fl);
	return (0);
}
