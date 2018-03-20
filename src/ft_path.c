/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:02:58 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 15:38:46 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_find_path(t_data *data, t_queue *ptr)
{
	t_pipe	*pipe_ptr;

	ptr = data->queue;
	while (ptr)
	{
		ptr->room->visited = 1;
		while (ptr->room->pipe)
		{
			pipe_ptr = ptr->room->pipe;
			if (ptr->room->pipe->to->visited == 0)
			{
				ptr->room->pipe->to->visited = 1;
				ptr->room->pipe->to->from = ptr->room;
				if (!ft_add_queue(data, ptr->room->pipe->to))
					return (0);
				if (ptr->room->pipe->to == data->E)
					return (1);
			}
			ptr->room->pipe = ptr->room->pipe->next;
			ft_memdel((void **)&pipe_ptr);
		}
		ptr = ptr->next;
	}
	return (0);
}

int		ft_path(t_data *data)
{
	t_queue *ptr;

	if ((data->max = min(ft_lst_len(data->S->pipe),
					ft_lst_len(data->E->pipe))) == 0)
		return (0);
	if (!ft_add_queue(data, data->S))
		return (0);
	ptr = data->queue;
	if (!ft_find_path(data, ptr))
	{
		ft_free_queue(data->queue);
		return (0);
	}
	ft_free_queue(ptr);
	return (1);
}
