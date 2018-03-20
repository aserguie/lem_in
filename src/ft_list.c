/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:51:45 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 22:32:12 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			ft_connect(t_data *data)
{
	t_rooms *ptr;

	if (data == NULL || data->e == NULL || data->s == NULL)
		return (0);
	ptr = data->s;
	ptr->next = data->rooms;
	ptr->rm_index = 0;
	data->rooms = ptr;
	ptr = data->last_room;
	if (ptr != NULL)
	{
		ptr->next = data->e;
		data->e->rm_index = ptr->rm_index + 1;
	}
	else
		data->s->next = data->e;
	data->last_room = data->e;
	return (1);
}

t_rooms		*ft_new_room(char **tab, t_data *data, int flag)
{
	t_rooms	*new;

	if ((new = malloc(sizeof(t_rooms))) == NULL)
		return (NULL);
	new->s = (flag == 1 ? 1 : 0);
	new->e = (flag == 2 ? 1 : 0);
	if (flag == 1)
		data->s = new;
	if (flag == 2)
		data->e = new;
	new->rm_name = ft_strdup(tab[0]);
	new->x = ft_strdup(tab[1]);
	new->y = ft_strdup(tab[2]);
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

int			ft_add_room(char **tab, t_data *data, int flag)
{
	if (tab == NULL || data == NULL)
		return (0);
	if (data->rooms == NULL)
	{
		if ((data->rooms = ft_new_room(tab, data, flag)) == NULL)
			return (0);
		data->last_room = data->rooms;
	}
	else if (data->last_room != NULL)
	{
		if ((data->last_room->next = ft_new_room(tab, data, flag)) == NULL)
			return (0);
		data->last_room = data->last_room->next;
	}
	return (1);
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

int			ft_add_line(char *line, t_data *data)
{
	if (line == NULL || data == NULL)
		return (0);
	if (data->output == NULL)
	{
		if ((data->output = ft_new_line(line)) == NULL)
			return (0);
		data->last_line = data->output;
	}
	if (data->last_line != NULL)
	{
		if ((data->last_line->next = ft_new_line(line)) == NULL)
			return (0);
		data->last_line = data->last_line->next;
	}
	return (1);
}
