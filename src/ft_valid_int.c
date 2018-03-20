/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:02:31 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 18:08:01 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_valid_int(char *str)
{
	int i;
	int len;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	i = 0;
	while (str[i] == '0')
		i++;
	if (!str[i])
		return (0);
	if ((len = ft_strlen(&str[i])) > 10)
		return (0);
	if (len == 10 && (str[0] > '2' || str[1] > '1' || str[2] > '4' ||
				str[3] > '7' || str[4] > '4' || str[5] > '8' || str[6] > '3' ||
				str[7] > '6' || str[8] > '4' || str[9] > '7'))
		return (0);
	return (1);
}

int		ft_valid_coord(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-' && str[i + 1])
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	i = 0;
	return (1);
}

int		ft_valid_name(char *str, t_data *data)
{
	t_rooms	*ptr;

	if (str == NULL)
		return (0);
	if (*str == 'L' || *str == '#' || *str == '\0' || ft_strchr(str, '-'))
		return (0);
	ptr = data->rooms;
	while (ptr)
	{
		if (!ft_strcmp(str, ptr->rm_name))
			return (0);
		ptr = ptr->next;
	}
	ptr = data->rooms;
	return (1);
}

int		ft_valid_pipe(char **str, t_data *data)
{
	t_rooms		*ptr;
	t_rooms		*e;
	t_rooms		*s;

	e = NULL;
	s = NULL;
	if (str == NULL)
		return (0);
	ptr = data->rooms;
	while (ptr)
	{
		if (!ft_strcmp(str[0], ptr->rm_name))
			e = ptr;
		if (!ft_strcmp(str[1], ptr->rm_name))
			s = ptr;
		ptr = ptr->next;
	}
	if (e != NULL && s != NULL && e != s)
	{
		if (!ft_add_pipe(e, s))
			return (0);
		if (!ft_add_pipe(s, e))
			return (0);
	}
	return (e != NULL && s != NULL && e != s);
}

int		ft_valid_room(char **tab, t_data *data, int flag)
{
	t_rooms *ptr;

	ptr = data->rooms;
	(void)flag;
	if (!ft_valid_name(*tab, data) || !ft_valid_coord(tab[1])
			|| !ft_valid_coord(tab[2]))
		return (0);
	while (ptr)
	{
		if (!ft_strcmp(tab[1], ptr->x) && !ft_strcmp(tab[2], ptr->y))
			return (0);
		ptr = ptr->next;
	}
	if (!ft_add_room(tab, data, flag))
		return (0);
	return (1);
}
