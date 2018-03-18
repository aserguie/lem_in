/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:58:33 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/18 21:13:34 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_init_board(t_data *data)
{
	int	i;

	i = 0;
	if (data->nb_rooms > 0 && data->board == NULL)
	{
		if ((data->board = (int **)ft_memalloc(sizeof(int*)
						* (data->nb_rooms + 1))) == NULL)
			return (0);
		while (i <= data->nb_rooms)
		{
			if ((data->board[i] = (int *)ft_memalloc(sizeof(int)
							* (data->nb_rooms + 1))) == NULL)
				return (0);
			i++;
		}
	}
	return (1);
}
