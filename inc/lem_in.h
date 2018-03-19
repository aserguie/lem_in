/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:27:22 by aserguie          #+#    #+#             */
/*   Updated: 2018/03/19 20:29:30 by aserguie         ###   ########.fr       */
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
/*
void			ft_free_set(t_set *set);
void			ft_set(t_set *set, t_set *game_set);
void			ft_display_stacks(t_set *set, int a_emptied);
int				ft_index(t_stack **stack);
int				ft_parse_flags(int ac, char **av, t_set **st_a);
int				ft_parse(int ac, char **av, t_set **set);
void			ft_create_node_list(t_stack **stack, int value, int index);
void			ft_create_node_cdll(t_stack **stack_1, t_stack **stack_2);
void			ft_erase_node_cdll(t_stack **stack);
void			ft_add_end_cdll(t_stack **stack, int value, int index);
void			ft_push_back_cdll(t_stack **stack_1, t_stack **stack_2);
void			ft_swap(t_stack **stack);
void			ft_rotate(t_stack **stack);
void			ft_rev_rotate(t_stack **stack);
void			ft_pop_node_cdll(t_stack **st_1, t_stack **st_2);
int				ft_is_numbers(char *str, int ctr);
int				ft_check_commands(char *line, t_stack **st_a, t_stack **st_b);
int				ft_sorted(t_stack **stack_a, t_stack **stack_b);
int				ft_min_max(t_stack **stack_a, t_stack **stack_b, int i);
int				ft_short(t_stack **curr, t_stack **help, t_stack **lst);
int				ft_long(t_stack **st_a, t_stack **st_b, t_stack **lst);
int				ft_merge(t_stack **st_a, t_stack **st_b, t_stack **lst);
void			ft_instruction(t_stack **lst, int instru);
int				ft_limits(char ***param);
long			ft_atoi_l(const char *str);
void			ft_display_instruction(t_stack **lst);
int				ft_target(t_set *set, t_cdll *stack_a, int a_emptied);
*/
#endif
