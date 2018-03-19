/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:32:04 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:35:29 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	char	*ft_unis(t_flags *f, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_fill(f->field - ft_strlen(str));
	tmp2 = ft_strjoin(tmp, str);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (tmp2);
}

static	char	*ft_uniz(t_flags *f, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_fill_0(f->pre - ft_strlen(str));
	tmp2 = ft_strjoin(tmp, str);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (tmp2);
}

char			*ft_is_pre(char *str, t_flags *fl)
{
	char *temp;
	char *temp2;

	temp = NULL;
	if (fl->pre <= (int)ft_strlen(str) && fl->field <= (int)ft_strlen(str))
		return (str);
	else if (fl->pre >= fl->field)
		return (ft_uniz(fl, str));
	else if (fl->field > fl->pre && fl->pre > (int)ft_strlen(str))
	{
		temp = ft_uniz(fl, str);
		temp2 = ft_unis(fl, temp);
		return (temp2);
	}
	else
		return (ft_unis(fl, str));
	return (NULL);
}
