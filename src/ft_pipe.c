/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:00:55 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 19:17:13 by aserguie         ###   ########.fr       */
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

int		ft_add_pipe(t_rooms *e, t_rooms *s)
{
	t_pipe *ptr;

	if (e->pipe == NULL)
	{
		if ((e->pipe = ft_new_pipe(s)) == NULL)
			return (0);
	}
	else if (e->pipe != NULL)
	{
		ptr = e->pipe;
		while (ptr->to->rm_index != s->rm_index && ptr->next)
			ptr = ptr->next;
		if (ptr->to->rm_index != s->rm_index)
			if ((ptr->next = ft_new_pipe(s)) == NULL)
				return (0);
	}
	return (1);
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

int		ft_add_queue(t_data *data, t_rooms *s)
{
	t_queue *ptr;

	if (data->queue == NULL)
	{
		if ((data->queue = ft_new_queue(data, s)) == NULL)
			return (0);
	}
	else
	{
		ptr = data->queue;
		while (ptr->next)
			ptr = ptr->next;
		if ((ptr->next = ft_new_queue(data, s)) == NULL)
			return (0);
	}
	return (1);
}

void	ft_free_queue(t_queue *queue)
{
	t_queue *ptr;

	while (queue != NULL)
	{
		ptr = queue;
		queue = queue->next;
		ft_memdel((void**)&ptr);
	}
}
