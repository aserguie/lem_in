/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:33 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/18 21:24:08 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		get_ants(char **line, t_data *data)
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
	if (*tab == NULL || *(tab + 1) != NULL)
		ret = -1;
	if (!ft_valid_int(*tab) || **tab == '-')
		ret = -1;
	else
		data->nb_ants = ft_atoi(tab[0]);
	ft_free_string_array(tab);
	ft_strdel(line);
	return (ret);
}

int		ft_start_end(char **tab, t_data *data)
{
	if (tab == NULL)
	{
		printf("!tab \n");
		return (-1);
	}
	else if ((!ft_strcmp(*tab, "##start") && (data->S || *(tab + 1) != NULL))
			|| (!ft_strcmp(*tab, "##end") && (data->E || *(tab + 1) != NULL)))
	{
		printf("datas->S = %d, data->E = %d\n", data->S->rm_index,
				data->E->rm_index);
		return (-1);
	}
	else if (!ft_strcmp(*tab, "##start"))
		return (1);
	else //if (!ft_strcmp(*tab, "##end"))
		return (2);
}

int		get_rooms(char **line, t_data *data)
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
		if ((ret = ft_skip(line, data)) <= 0)
			return (-1);
		if ((tab = ft_strsplit(*line, ' ')) == NULL)
			ft_error(data);
		if (**tab == '#' && !flag)
			flag = ft_start_end(tab, data);
		else
		{
			if (*tab == NULL || *(tab + 1) == NULL || *(tab + 2) == NULL
					|| *(tab + 3) != NULL)
				ret = (flag ? -1 : 0);
			else if (!ft_valid_room(tab, data, flag))
				ret = -1;
			else
				flag = 0;
			ft_free_string_array(tab);
		}
		if (ret != 0)
			ft_strdel(line);
	}
	if (flag && !ret)
		ft_free_string_array(tab);
	return (min(ret, flag));
}

int		get_pipes(char **line, t_data *data)
{
	char	**tab;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		if ((tab = ft_strsplit(*line, '-')) == NULL)
		{
			ft_error(data);
		}
		else
		{
			if (*tab == NULL || *(tab + 1) == NULL || *(tab + 2) != NULL)
				ret = 0;
			if (!ft_valid_pipe(tab, data))
				ret = -1;
		}
		ft_strdel(line);
		ft_free_string_array(tab);
		if (ret > 0)
			if ((ret = ft_skip(line, data)) <= 0)
				return (ret);
	}
	ft_strdel(line);
	return (ret);
}

int		ft_read(t_data *data)
{
	char	*line;

	line = NULL;
	if (get_ants(&line, data) < 0)
	{
		ft_error(data);
		return (-1);
	}
	printf("------ GOT ANTS ------\n");
	if (get_rooms(&line, data) < 0 || !ft_connect(data))
	{
		ft_error(data);
		return (-1);
	}
	printf("------ GOT ROOMS ------\n");
	printf("%d\n\n", data->nb_rooms);
	printf("start = %s\t", data->S->rm_name);
	printf("end = %s\n", data->E->rm_name);
	if (get_pipes(&line, data) < 0)
	{
		ft_error(data);
		return (-1);
	}
	printf("------ GOT PIPES ------\n");
	if (!ft_path(data))
	{
		ft_error(data);
		return (-1);
	}
	return (1);
}
