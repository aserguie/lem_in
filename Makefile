# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aserguie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 14:27:31 by aserguie          #+#    #+#              #
#    Updated: 2018/03/19 20:30:49 by aserguie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

CC = gcc

FLAGS = -Werror -Wall -Wextra #-fsanitize=address

SRC = lem_in.c \
	  ft_read.c \
	  ft_free_string_array.c \
	  ft_list.c \
	  ft_valid_int.c \
	  ft_skip.c \
	  ft_board.c \
	  ft_path.c \
	  ft_pipe.c \
	  ft_lst_len.c \
	  ft_print_answer.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

SRC_DIR = ./src/

INC_DIR  = ./inc/

OBJ_DIR = ./obj/

HEADERS = $(INC_DIR) $(LIB_DIR)

LIB_DIR = ./libft

LIBFT = $(LIB_DIR)/libft.a

all : mklib $(NAME)

$(NAME)			:	$(OBJ_DIR) $(LIBFT) $(OBJ) $(HEADERS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -I$(INC_DIR) -I$(LIB_DIR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c $(HEADERS) $(LIBFT)
		$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIB_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

mklib:
	make -C $(LIB_DIR) 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

clean_lib:
	rm -f $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean_lib:clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re_lib:fclean_lib all

.PHONY:all clean fclean re mklib
