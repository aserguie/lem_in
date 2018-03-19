/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nega.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:52:23 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:28:47 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	char	*ft_minus(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str[i] != ' ')
		return (str);
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		str[j] = str[i];
		j++;
		i++;
	}
	while (str[j] != '\0')
	{
		str[j] = ' ';
		j++;
	}
	return (str);
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
	temp = NULL;
	if (f->pre >= f->field)
	{
		temp = ft_strjoin("-", str);
		return (temp);
	}
	if (!(ft_strchr(f->attr, '-')))
		if (ft_strchr(f->attr, '0'))
			str = ft_is_zero(str, f);
	while (str[i] == ' ')
		i++;
	if (i != 0)
		str[i - 1] = '-';
	else if (f->field > a)
		str[i] = '-';
	else
	{
		temp = ft_strjoin("-", str);
		return (temp);
	}
	return (str);
}

int				ft_nega(char *str, t_flags *fl)
{
	char	*finish;
	char	*strattr;
	int		a;

	a = 0;
	finish = NULL;
	strattr = NULL;
	a = ft_strlen(str);
	strattr = ft_is_pre(str, fl);
	finish = ft_is_plus(strattr, fl, a);
	if (ft_strchr(fl->attr, '-'))
		finish = ft_minus(finish);
	ft_putstr(finish);
	fl->count = ft_strlen(finish);
	return (0);
}
