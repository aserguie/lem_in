/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:38:46 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/18 21:19:24 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		is_comment(char *line)
{
	if (line == NULL)
		return (0);
	if (*line == '#')
		if (*(line + 1) != '#' || (ft_strcmp(line, "##start")
					&& ft_strcmp(line, "##end")))
			return (1);
	return (0);
}

int		ft_skip(char **line, t_data *data)
{
	int ret;

	if ((ret = get_next_line(0, line)) <= 0)
		return (ret);
	while (is_comment(*line))
	{
		ft_add_line(*line, data);
		ft_strdel(line);
		if ((ret = get_next_line(0, line)) <= 0)
			return (ret);
	}
	ft_add_line(*line, data);
	return (1);
}
