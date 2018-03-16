# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aserguie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 16:16:13 by aserguie          #+#    #+#              #
#    Updated: 2018/03/16 19:51:56 by aserguie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra #-fsanitize=address
NAME=libft.a
SRC= ft_atoi.c \
	 ft_bzero.c \
	 ft_isalnum.c \
	 ft_isalpha.c \
	 ft_isascii.c \
	 ft_isdigit.c \
	 ft_isprint.c \
	 ft_itoa.c \
	 ft_lstadd.c \
	 ft_lstdel.c \
	 ft_lstdelone.c \
	 ft_lstiter.c \
	 ft_lstmap.c \
	 ft_lstnew.c \
	 ft_memalloc.c \
	 ft_memccpy.c \
	 ft_memchr.c \
	 ft_memcmp.c \
	 ft_memcpy.c \
	 ft_memdel.c \
	 ft_memmove.c \
	 ft_memset.c \
	 ft_putchar.c \
	 ft_putchar_fd.c \
	 ft_putendl.c \
	 ft_putendl_fd.c \
	 ft_putstr.c \
	 ft_putstr_fd.c \
	 ft_putnbr.c \
	 ft_putnbr_fd.c \
	 ft_strcat.c \
	 ft_strchr.c \
	 ft_strclr.c \
	 ft_strcmp.c \
	 ft_strcpy.c \
	 ft_strdel.c \
	 ft_strdup.c \
	 ft_strequ.c \
	 ft_striter.c \
	 ft_striteri.c \
	 ft_strjoin.c \
	 ft_strlcat.c \
	 ft_strlen.c \
	 ft_strmap.c \
	 ft_strmapi.c \
	 ft_strncat.c \
	 ft_strncmp.c \
	 ft_strncpy.c \
	 ft_strnequ.c \
	 ft_strnew.c \
	 ft_strnstr.c \
	 ft_strrchr.c \
	 ft_strsplit.c \
	 ft_strstr.c \
	 ft_strsub.c \
	 ft_strtrim.c \
	 ft_tolower.c \
	 ft_toupper.c \
	 get_next_line.c

SRC_DIR = ./src/

OBJ_DIR = ./obj/

OBJ= $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

HEADERS = ./inc/libft.h

all:	$(NAME)

test:
	echo $(OBJ)

$(NAME): $(OBJ_DIR) $(OBJ) $(INC_DIR)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC_DIR) $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re
