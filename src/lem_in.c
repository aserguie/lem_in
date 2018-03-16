/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:21:12 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/16 22:32:09 by aserguie         ###   ########.fr       */
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
	data->S = NULL;
	data->E = NULL;
}

void	ft_free_output(t_output *output)
{
	t_output *ptr;

	ptr = NULL;
	while (output != NULL)
	{
		ptr = output;
		free(output->line);
		output = output->next;
		free(ptr);
	}
}

void	ft_free_rooms(t_rooms *room)
{
	t_rooms *ptr;

	ptr = NULL;
	while (room != NULL)
	{
		ptr = room;
		free(room->rm_name);
		free(room->x);
		free(room->y);
		room = room->next;
		free(ptr);
	}
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		ft_free_output(data->output);
		ft_free_rooms(data->rooms);
	}
//	free(data);
}

void	ft_error(t_data *data)
{
	ft_free_data(data);
	printf("ERROR\n");
	exit (-1);
}

int main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	ft_init(&data);
	ft_read(&data);
	if (ac > 1)
	{
		printf("------------------------------------\n");
		printf("RENDU\n------------------------------------\n");
		while (data.output)
		{
			printf("%s\n", data.output->line);
			data.output = data.output->next;
		}
		printf("------------------------------------\n");
		printf("DATA\n------------------------------------\n");
		while (data.rooms)
		{
			printf("index = %d, x =  %s, y = %s, START = %d, END = %d\n", data.rooms->rm_index, data.rooms->x, data.rooms->y, data.rooms->S, data.rooms->E);
			data.rooms = data.rooms->next;

		}
		printf("------------------------------------\n");
	}
	ft_free_data(&data);
	return(0);
}
