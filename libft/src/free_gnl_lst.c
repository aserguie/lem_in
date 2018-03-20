/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gnl_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:52:48 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 16:22:24 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	del(t_block *fd)
{
	if (fd != NULL)
	{
		if (fd->content != NULL)
			ft_strdel(&fd->content);
		free(fd);
	}
}

int			free_gnl_lst(t_block **lst)
{
	t_block *ptr;

	if (lst && *lst)
	{
		while ((*lst))
		{
			ptr = *lst;
			(*lst) = (*lst)->next;
			del(ptr);
		}
		ft_memdel((void **)lst);
	}
	return (0);
}
