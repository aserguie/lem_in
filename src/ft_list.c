/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:51:45 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 01:00:13 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			ft_connect(t_data *data)
{
	t_rooms *ptr;

	if (data == NULL || data->E == NULL || data->S == NULL)
		return (0);
	ptr = data->S;
	ptr->next = data->rooms;
	ptr->rm_index = 0;
	data->rooms = ptr;
	ptr = data->last_room;
	if (ptr != NULL)
	{
		ptr->next = data->E;
		data->E->rm_index = ptr->rm_index + 1;
	}
	else
		data->S->next = data->E;
	data->last_room = data->E;
	return (1);
}

t_rooms		*ft_new_room(char **tab, t_data *data, int flag)
{
	t_rooms	*new;

	if ((new = malloc(sizeof(t_rooms))) == NULL)
		return (NULL);
	new->S = (flag == 1 ? 1 : 0);
	new->E = (flag == 2 ? 1 : 0);
	if (flag == 1)
		data->S = new;
	if (flag == 2)
		data->E = new;
	new->rm_name = ft_strdup(tab[0]);
	new->x = ft_strdup(tab[1]);
	new->y = ft_strdup(tab[2]);
	if (flag)
		new->rm_index = (flag == 1 ? 0 : -1);
	else
		new->rm_index = (data->rooms == NULL ? 1 :
			(data->last_room->rm_index) + 1);
	new->visited = 0;
	new->from = NULL;
	new->pipe = NULL;
	new->next = NULL;
	new->ant = 0;
	data->nb_rooms++;
	return (new);
}

void		ft_add_room(char **tab, t_data *data, int flag)
{
	if (tab == NULL || data == NULL)
		return ;
	if (flag == 1)
		data->S = ft_new_room(tab, data, flag);
	else if (flag == 2)
		data->E = ft_new_room(tab, data, flag);
	else if (data->rooms == NULL)
	{
		data->rooms = ft_new_room(tab, data, flag);
		data->last_room = data->rooms;
	}
	else if (data->last_room != NULL)
	{
		data->last_room->next = ft_new_room(tab, data, flag);
		data->last_room = data->last_room->next;
	}
}

t_output	*ft_new_line(char *line)
{
	t_output	*new;

	if ((new = malloc(sizeof(t_output))) == NULL)
		return (NULL);
	new->next = NULL;
	new->line = ft_strdup(line);
	return (new);
}

void		ft_add_line(char *line, t_data *data)
{
	if (line == NULL || data == NULL)
		return ;
	if (data->output == NULL)
	{
		data->output = ft_new_line(line);
		data->last_line = data->output;
		return ;
	}
	if (data->last_line != NULL)
	{
		data->last_line->next = ft_new_line(line);
		data->last_line = data->last_line->next;
	}
}
