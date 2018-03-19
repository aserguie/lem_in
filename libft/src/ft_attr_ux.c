/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attr_ux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:47:51 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:25:42 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	void	ft_zzero(char *str, t_flags *f)
{
	int		i;

	i = 0;
	if (f->pre != -1)
		return ;
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	if (ft_strchr(f->attr, '#'))
	{
		while (str[i] != 'x')
			i++;
		str[i] = '0';
		str[1] = 'x';
	}
}

static	char	*ft_tag2(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (str[0] != ' ')
	{
		temp = ft_strjoin("0x", str);
		ft_strdel(&str);
		return (temp);
	}
	while (str[i] == ' ')
		i++;
	if (i > 1)
	{
		str[i - 1] = 'x';
		str[i - 2] = '0';
		return (str);
	}
	str[i - 1] = 'x';
	temp = ft_strjoin("0", str);
	ft_strdel(&str);
	return (temp);
}

static	char	*ft_tag(char *str, t_flags *f, int a)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = 0;
	if (f->conv == 'o' || f->conv == 'O')
	{
		if (a >= f->field && a >= f->pre)
		{
			temp = ft_strjoin("0", str);
			return (temp);
		}
		if (f->pre > a)
			return (str);
		str[f->field - a - 1] = '0';
		return (str);
	}
	if ((f->conv == 'x' || f->conv == 'X'))
	{
		temp = ft_tag2(str);
		return (temp);
	}
	ft_strdel(&str);
	return (temp);
}

static	char	*ft_minus(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str)
	{
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
	}
	return (str);
}

int				ft_attr_ux(char *str, t_flags *f)
{
	char	*finish;
	char	*temp;
	int		a;

	a = ft_strlen(str);
	temp = NULL;
	finish = NULL;
	finish = ft_is_pre(str, f);
	if (ft_strchr(f->attr, '#'))
		temp = ft_tag(finish, f, a);
	else
		temp = finish;
	if (ft_strchr(f->attr, '-'))
		ft_minus(temp);
	if (ft_strchr(f->attr, '0'))
		ft_zzero(temp, f);
	if (f->conv == 'O' || f->conv == 'X')
		ft_upper(temp);
	ft_putstr(temp);
	f->count = ft_strlen(temp) + f->count;
	ft_strdel(&temp);
	return (0);
}
