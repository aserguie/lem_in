/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:25:35 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:12 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = (*f)(lst);
		if (first)
		{
			current->next = new;
			current = current->next;
		}
		else
		{
			first = new;
			current = first;
		}
		lst = lst->next;
	}
	return (first);
}
