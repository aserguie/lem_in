/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:27:22 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/20 02:59:03 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define min(a,b) (a < b ? a : b)
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/inc/libft.h"

typedef struct			s_pipe
{
	struct s_rooms		*to;
	struct s_pipe		*next;
}						t_pipe;

typedef struct			s_rooms
{
	int					ant;
	int					S;
	int					E;
	char				*x;
	char				*y;
	char				*rm_name;
	int					rm_index;
	int					visited;
	struct s_rooms		*from;
	t_pipe				*pipe;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_queue
{
	struct s_rooms		*room;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_output
{
	char				*line;
	struct	s_output	*next;
}						t_output;

typedef struct	s_data
{

	t_output	*output;
	t_output	*last_line;
	t_rooms		*S;
	t_rooms		*E;
	t_rooms		*rooms;
	t_rooms		*last_room;
	t_queue		*queue;
	t_queue		**paths;
	t_rooms		**board;
	int			max;
	int			nb_rooms;
	int			nb_ants;
}				t_data;

int				ft_count_char(char *str, char c);
void			ft_print_answer(t_data *data);
int				ft_lst_len(t_pipe *lst);
int				ft_connect(t_data *data);
int				ft_path(t_data *data);
int				ft_init_board(t_data *data, int nth_path, int nth_len);
void			ft_add_line(char *line, t_data *data);
void			ft_add_room(char **tab, t_data *data, int flag);
void			ft_add_pipe(t_rooms *e, t_rooms *s);
void			ft_add_queue(t_data *data, t_rooms *s);
int				ft_read(t_data *data);
int				ft_skip(char **line, t_data *data);
int				ft_valid_int(char *str);
int				ft_valid_room(char **str, t_data *data, int flag);
int				ft_valid_pipe(char **str, t_data *data);
void			ft_free_string_array(char **tab);
void			ft_error(t_data *data);
void			ft_free_queue(t_queue *queue);

#endif
