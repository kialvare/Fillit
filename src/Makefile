#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phoreau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/28 21:58:43 by phoreau           #+#    #+#              #
#    Updated: 2016/11/28 15:56:35 by kialvare         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=fillit

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=/bin/rm -f

LIB=libft.a

LDFLAGS=-L./libft/

LDLIBS=-lft

SRC=main.c \
	read_map.c \
	algo3.c \
	convert.c \
	map.c \
	count_tetri.c 

all: $(NAME)

$(LIB):
	make -C ./libft

OBJ := $(patsubst %.c,%.o,$(SRC))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
