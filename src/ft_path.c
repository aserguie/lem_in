/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:02:58 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:58:52 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_find_path(t_data *data)
{
	t_queue *ptr;
	t_pipe	*pipe_ptr;

	ft_add_queue(data, data->S);
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
				ft_add_queue(data, ptr->room->pipe->to);
				if (ptr->room->pipe->to == data->E)
					return (1);
			}
			ptr->room->pipe = ptr->room->pipe->next;
			ft_memdel((void **)&pipe_ptr);
		}
		ptr = ptr->next;
	}
//	if (data->E->visited == 1)
//		return (1);
	return (0);
}

int		ft_path(t_data *data)
{
	if ((data->max = min(ft_lst_len(data->S->pipe),
					ft_lst_len(data->E->pipe))) == 0)
		return (0);
	if (!ft_find_path(data))
		return (0);
	return (1);
}
