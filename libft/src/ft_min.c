/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:49:15 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:27:18 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	char	*ft_minspace(char *str, t_flags *f, int a)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	temp = NULL;
	if (f->field > f->pre && f->field > a)
	{
		while (str[i] != ' ')
			i++;
		j = i - 1;
		while (i > 0)
		{
			str[i] = str[j];
			i--;
			j--;
		}
		str[i] = ' ';
		return (str);
	}
	else
		temp = ft_strjoin(" ", str);
	return (temp);
}

static	char	*ft_minadd(char *str, t_flags *f, int a)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	temp = NULL;
	if (f->field > f->pre && f->field > a)
	{
		while (str[i] != ' ')
			i++;
		j = i - 1;
		while (i > 0)
		{
			str[i] = str[j];
			i--;
			j--;
		}
		str[i] = '+';
		return (str);
	}
	else
		temp = ft_strjoin("+", str);
	return (temp);
}

char			*ft_min(char *str, t_flags *fl, int a)
{
	int		i;
	int		j;
	int		c;
	char	*temp;

	temp = NULL;
	c = 0;
	j = 0;
	i = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		while (str[i] != '\0')
			str[j++] = str[i++];
		while (str[j] != '\0')
			str[j++] = ' ';
	}
	if (ft_strchr(fl->attr, '+'))
		return (temp = ft_minadd(str, fl, a));
	else if (ft_strchr(fl->attr, ' '))
		return (temp = ft_minspace(str, fl, a));
	return (str);
}
