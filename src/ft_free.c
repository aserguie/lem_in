/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:56:10 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 18:13:07 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_free_output(t_output *output)
{
	t_output *ptr;

	ptr = NULL;
	while (output != NULL)
	{
		ptr = output;
		ft_strdel(&(output->line));
		output = output->next;
		ft_memdel((void**)&ptr);
	}
}

void	ft_free_pipes(t_pipe *pipe)
{
	t_pipe *ptr;

	ptr = NULL;
	while (pipe != NULL)
	{
		ptr = pipe;
		pipe = pipe->next;
		ft_memdel((void**)&ptr);
	}
}

void	ft_free_rooms(t_rooms *room)
{
	t_rooms *ptr;

	ptr = NULL;
	while (room != NULL)
	{
		ptr = room;
		ft_strdel(&room->rm_name);
		ft_strdel(&room->x);
		ft_strdel(&room->y);
		ft_free_pipes(room->pipe);
		room = room->next;
		ft_memdel((void**)&ptr);
	}
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		ft_free_output(data->output);
		ft_free_rooms(data->rooms);
		get_next_line(0, FREE);
	}
}
