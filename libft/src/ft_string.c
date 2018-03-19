/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:33:15 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:29:58 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	char		*ft_minus(char *str, t_flags *f, int a)
{
	int		i;

	if (f->pre > 0 && f->pre < a)
		a = f->pre;
	if (f->pre == 0)
		return (str);
	i = 0;
	if (!(str))
		return (NULL);
	if (f->field <= a)
		return (str);
	while (str[f->field - a] != '\0')
	{
		str[i] = str[f->field - a];
		i++;
		f->field++;
	}
	while (str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

static	char		*ft_dup(char *str)
{
	char	*dup;
	int		i;

	dup = NULL;
	i = 0;
	if (!(str))
		return (NULL);
	if (!(dup = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static	char		*ft_str(char *str, t_flags *f, int a)
{
	char	*s;
	char	*temp;
	char	*strnew;
	int		i;

	temp = NULL;
	strnew = ft_dup(str);
	i = f->pre;
	if (f->pre < a)
	{
		while (strnew[i] != '\0')
		{
			strnew[i] = '\0';
			i++;
		}
	}
	a = ft_strlen(strnew);
	if (f->field > a)
		temp = ft_fill(f->field - a);
	s = ft_strjoin(temp, strnew);
	return (s);
}

static	char		*ft_isfield(char *str, t_flags *fl)
{
	char	*s;
	char	*temp;
	char	*strnew;
	int		a;

	s = NULL;
	temp = NULL;
	if (!(str))
		return (NULL);
	strnew = ft_dup(str);
	a = ft_strlen(strnew);
	if (fl->field > a)
		temp = ft_fill(fl->field - a);
	s = ft_strjoin(temp, strnew);
	return (s);
}

int					ft_string(char *str, t_flags *fl, int a)
{
	char	*s;

	if (fl->pre == -1)
		s = ft_isfield(str, fl);
	if (fl->pre > 0)
		s = ft_str(str, fl, a);
	if (!(fl->attr))
	{
		ft_putstr(s);
		fl->count = ft_strlen(s);
		ft_strdel(&s);
		return (0);
	}
	if (fl->attr[0] == '-' || fl->attr[1] == '-')
		ft_minus(s, fl, a);
	ft_putstr(s);
	fl->count = ft_strlen(s);
	ft_strdel(&s);
	return (0);
}
