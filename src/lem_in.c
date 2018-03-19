/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:21:12 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:47:25 by aserguie         ###   ########.fr       */
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
	data->S = NULL;
	data->E = NULL;
	data->queue = NULL;
	data->board = NULL;
	data->paths = NULL;
}

void	ft_free_board(t_data *data)
{
	int	i;

	i = 0;
	if (data->board != NULL)
	{
		while (data->board[i] != NULL && i < data->nb_rooms)
		{
			ft_memdel((void **)&data->board[i]);
			i++;
		}
		ft_memdel((void**)&data->board);
	}
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

void	ft_free_pipes(t_pipe *pipe)
{
	t_pipe *ptr;

	ptr = NULL;
	while (pipe != NULL)
	{
		ptr = pipe;
//		free(pipe->to);
		pipe = pipe->next;
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
		ft_free_pipes(room->pipe);
		room = room->next;
		free(ptr);
	}
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		ft_free_board(data);
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

	int i = 0;
	int j;
	(void)ac;
	(void)av;
	ft_init(&data);
	ft_read(&data);
	if (ac > 2)
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
	if (ac > 1)
	{
		while (i <= data.nb_rooms)
		{
			j = 0;
			while (j <= data.nb_rooms)
			{
//				printf("%d\t", data.board[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		printf("------------------------------------\n");
	}
	ft_free_data(&data);
	return(0);
}

//Supprimer board et tout ce aui va avec si je ne m'en sers pas au final

//Attention quand je trouve un path je me ballade vraiment dans les pipes alors
//que je devrais simplement changer l'adresse pointee du coup je peux plus free a la fin...

// Attention quand je compile avec f_sanitize il ya des erreurs(tester avec fsani dans le makefile, puis dans celui de la libft puis dans les deux)

// Attention segfault si mon fichier finit par un newlne !! (verifier aussi avec et sans \n,  EOF...)
//
//  Comment gerer si il ya plusieurs connexions entre deux salles?
//
//  Si il faut le gerer, faire en sorte que si une connexion existe deja entre deux salles on la skippe si on la revoit
