/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:33 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 22:34:33 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_get_ants(char **line, t_data *data)
{
	char	**tab;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (ft_skip(line, data) < 0)
		return (-1);
	if ((tab = ft_strsplit(*line, ' ')) == NULL)
		ft_error(data);
	if (*tab == NULL || *(tab + 1) != NULL || ft_strchr(*line, ' '))
		ret = -1;
	if (!ft_valid_int(*tab) || **tab == '-')
		ret = -1;
	else
		data->nb_ants = ft_atoi(tab[0]);
	ft_strdel(line);
	ft_free_string_array(tab);
	return (ret);
}

int		ft_start_end(char **tab, t_data *data)
{
	if (tab == NULL)
		return (-1);
	else if ((!ft_strcmp(*tab, "##start") && (data->s || *(tab + 1) != NULL))
			|| (!ft_strcmp(*tab, "##end") && (data->e || *(tab + 1) != NULL)))
		return (-1);
	else if (!ft_strcmp(*tab, "##start"))
		return (1);
	else
		return (2);
}

void	ft_get_rooms_2(char **tab, t_data *data, int *flag, int *ret)
{
	if (*tab && *tab[0] == '#' && !(*flag))
		*flag = ft_start_end(tab, data);
	else
	{
		if (*tab == NULL || *(tab + 1) == NULL || *(tab + 2) == NULL
				|| *(tab + 3) != NULL)
			*ret = (*flag ? -1 : 0);
		else if (!ft_valid_room(tab, data, *flag))
			*ret = -1;
		else
			*flag = 0;
		ft_free_string_array(tab);
	}
}

int		ft_get_rooms(char **line, t_data *data)
{
	char	**tab;
	int		ret;
	int		flag;

	flag = 0;
	ret = 1;
	while (ret > 0 && flag >= 0)
	{
		if (flag)
			ft_free_string_array(tab);
		if (!line || (ret = ft_skip(line, data)) <= 0 || ft_strlen(*line) == 0)
		{
			ft_strdel(line);
			return (-1);
		}
		if ((tab = ft_strsplit(*line, ' ')) == NULL || **line == ' '
				|| (*line[0] == '#' && (ft_strchr(*line, ' ')))
				|| ft_count_char(*line, ' ') > 2)
			ft_error(data);
		ft_get_rooms_2(tab, data, &flag, &ret);
		(ret != 0 ? ft_strdel(line) : ft_strdel(NULL));
	}
	if (flag && !ret)
		ft_free_string_array(tab);
	return (ft_mini(ret, flag));
}

int		ft_get_pipes(char **line, t_data *data)
{
	char	**tab;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		if ((tab = ft_strsplit(*line, '-')) == NULL)
			return (-1);
		else
		{
			if (*tab == NULL || *(tab + 1) == NULL || *(tab + 2) != NULL)
				ret = 0;
			else if (ft_strchr(*line, '-') != ft_strrchr(*line, '-')
					|| !ft_valid_pipe(tab, data))
				ret = -1;
		}
		ft_strdel(line);
		ft_free_string_array(tab);
		if (ret > 0)
			if ((ret = ft_skip(line, data)) <= 0)
				if (ft_strlen(*line) == 0 || (ret && **line == '#'))
					ret--;
	}
	ft_strdel(line);
	return (ret);
}
