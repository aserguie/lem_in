/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:21:12 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 22:54:07 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	ft_init(t_data *data)
{
	data->output = NULL;
	data->last_line = NULL;
	data->rooms = NULL;
	data->last_room = NULL;
	data->nb_rooms = 0;
	data->nb_ants = 0;
	data->max = 0;
	data->s = NULL;
	data->e = NULL;
	data->queue = NULL;
}

void	ft_error(t_data *data)
{
	ft_free_data(data);
	get_next_line(0, FREE);
	ft_putstr("ERROR\n");
	exit(-1);
}

int		ft_read(t_data *data)
{
	char	*line;

	line = NULL;
	if (ft_get_ants(&line, data) < 0)
		ft_error(data);
	if (ft_get_rooms(&line, data) < 0 || !data->s || !data->e)
		ft_error(data);
	if (ft_get_pipes(&line, data) < 0 && (data->s->pipe == NULL
				|| data->e->pipe == NULL))
		ft_error(data);
	if (!ft_path(data))
		ft_error(data);
	ft_print_answer(data);
	return (1);
}

int		main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	ft_init(&data);
	ft_read(&data);
	ft_free_data(&data);
	return (0);
}
