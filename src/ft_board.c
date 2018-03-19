/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:58:33 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 20:16:18 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_init_board(t_data *data, int nth_path, int nth_len)
{
	if (data->board == NULL)
	{
		if ((data->board = (t_rooms **)ft_memalloc(sizeof(t_rooms*)
						* (data->max + 1))) == NULL)
			return (0);
	}
	nth_path = nth_len;
	if (data->board[nth_path] == NULL)
	{
		if ((data->board[nth_path] = (t_rooms *)ft_memalloc(sizeof(t_rooms)
						* (nth_len))) == NULL)
			return (0);
	}
	return (1);
}
