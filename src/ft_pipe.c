/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:00:55 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/18 21:18:14 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_pipe	*ft_new_pipe(t_rooms *s)
{
	t_pipe	*new;

	if ((new = malloc(sizeof(t_pipe))) == NULL)
		return (NULL);
	new->to = s;
	new->next = NULL;
	return (new);
}

void	ft_add_pipe(t_rooms *e, t_rooms *s)
{
	t_pipe *ptr;

	if (e->pipe == NULL)
		e->pipe = ft_new_pipe(s);
	else if (e->pipe != NULL)
	{
		ptr = e->pipe;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = ft_new_pipe(s);
	}
	if (!s->next)
		ft_add_pipe(s, e);
}

t_queue	*ft_new_queue(t_data *data, t_rooms *s)
{
	t_queue	*new;

	if ((new = malloc(sizeof(t_queue))) == NULL)
		return (NULL);
	new->room = s;
	new->next = NULL;
	data->queue = new;
	return (new);
}

void	ft_add_queue(t_data *data, t_rooms *s)
{
	t_queue *ptr;

	if (data->queue == NULL)
		data->queue = ft_new_queue(data, s);
	else
	{
		ptr = data->queue;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = ft_new_queue(data, s);
	}
}
/*
void	ft_dequeue(t_data *data)
{
	t_queue *ptr;

	if (data->queue != NULL)
	{
		ptr = data->queue;
		data->queue = data->queue->next;
		ptr = NULL;
	}
}*/

// Penser a liberer la queue,(est elle seulement utile?)
