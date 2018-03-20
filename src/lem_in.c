/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:21:12 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 18:59:11 by aserguie         ###   ########.fr       */
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
}

void	ft_error(t_data *data)
{
	ft_free_data(data);
	get_next_line(0, FREE);
	ft_putstr("ERROR\n");
	exit (-1);
}

int main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	ft_init(&data);
	ft_read(&data);
	ft_free_data(&data);
	return(0);
}

//Attention quand je trouve un path je me ballade vraiment dans les pipes alors
//que je devrais simplement changer l'adresse pointee du coup je peux plus free a la fin...

// Attention quand je compile avec f_sanitize il ya des erreurs(tester avec fsani dans le makefile, puis dans celui de la libft puis dans les deux)

// Attention segfault si mon fichier finit par un newlne !! (verifier aussi avec et sans \n,  EOF...)
