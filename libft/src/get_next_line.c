/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:57:56 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 20:55:14 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	unsigned int	find(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static	t_block			*ft_new_fd(char *content, int fd)
{
	t_block	*new;

	if (!(new = (t_block*)malloc(sizeof(*new))))
		return (NULL);
	if (content[0] == '\0')
	{
		new->content = ft_strnew(0);
		new->fd = fd;
	}
	new->next = NULL;
	return (new);
}

static	int				ft_pick_node(const int fd, t_block **tmp,
		t_block **node)
{
	t_block *a;
	t_block *b;

	b = *node;
	a = *tmp;
	if (!b)
		b = ft_new_fd("", fd);
	if (!b)
		return (0);
	a = b;
	while (a && (a->fd != fd))
		a = a->next;
	if (a == NULL)
	{
		a = ft_new_fd("", fd);
		if (!a)
			return (0);
		a->next = b;
		b = a;
	}
	*tmp = a;
	*node = b;
	return (1);
}

static	void			ft_split(char *temp, t_block *tmp, char **line)
{
	unsigned int n;

	n = find(tmp->content);
	*line = ft_strsub(tmp->content, 0, n);
	if (tmp->content + n == '\0')
		*temp = '\0';
	else
		temp = ft_strsub(tmp->content, (n + 1),
			ft_strlen(&(tmp->content[n])));
	ft_strdel(&(tmp->content));
	tmp->content = ft_strdup(temp);
	ft_strdel(&temp);
}

int						get_next_line(const int fd, char **line)
{
	static t_block	*node = NULL;
	t_block			*tmp;
	char			buf[BUFF_SIZE + 1];
	ssize_t			ret;
	char			*temp;

	tmp = NULL;
	temp = NULL;
	if (line == FREE || fd < 0 || !line || ft_pick_node(fd, &tmp, &node) <= 0)
		return ((line == FREE ? free_gnl_lst(&node) : -1));
	while (!(ft_strchr(tmp->content, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
			break ;
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		temp = ft_strjoin(tmp->content, buf);
		ft_strdel(&(tmp->content));
		tmp->content = temp;
	}
	if (ft_strlen(tmp->content) == 0)
		return (0);
	ft_split(temp, tmp, line);
	return (1);
}
