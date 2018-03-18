/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:02:58 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/18 21:45:41 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_find_path(t_data *data)
{
	t_queue *ptr;

	ft_add_queue(data, data->S);
	ptr = data->queue;
	while (ptr)
	{
		ptr->room->visited = 1;
		while (ptr->room->pipe)
		{
			if (ptr->room->pipe->to->visited == 0)
			{
				ptr->room->pipe->to->visited = 1;
				ptr->room->pipe->to->from = ptr->room;
				ft_add_queue(data, ptr->room->pipe->to);
				if (ptr->room->pipe->to == data->E)
					return (1);
			}
			ptr->room->pipe = ptr->room->pipe->next;
		}
		ptr = ptr->next;
	}
	if (data->E->visited == 1)
		return (1);
	return (0);
}

void	ft_display_path(t_data *data)
{
	t_rooms *ptr;
	ptr = data->E;
	while (ptr != NULL)
	{
		printf("%s", ptr->rm_name);
		if (ptr->from)
			printf (" from ");
		ptr = ptr->from;
	}
	printf("\n");
}

int		ft_path(t_data *data)
{
	if (data->S->pipe == NULL || data->E->pipe == NULL)
		return (0);
	if (!ft_find_path(data))
		return (0);
	ft_display_path(data);
	return (1);
}
