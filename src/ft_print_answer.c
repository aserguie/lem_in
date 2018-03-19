/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:27:41 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 23:47:59 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"


void	ft_print_data(t_data *data)
{
	while (data->output)
	{
		ft_printf("%s\n",data->output->line);
		data->output = data->output->next;
	}
}

void	ft_print_answer(t_data *data)
{
	int empty;;
	t_rooms *ptr;

	empty = 0;
	ft_print_data(data);
	while (data->E->ant != data->nb_ants)
	{
		ptr = data->E;
		while (ptr->from->ant == 0 && ptr->from != data->S)
			ptr = ptr->from;
		while (ptr->from && ptr->ant < data->nb_ants)
		{
			if (empty == 0 && ptr->ant < data->nb_ants)
				ptr->ant++;
			else if (empty == 0)
				empty = 1;
			else
				ptr->ant = 0;
			ft_printf("L%d-%s ", ptr->ant, ptr->rm_name);
			ptr = ptr->from;
		}
		ft_printf("\n");
	}
}
