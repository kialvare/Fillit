# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kialvare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 09:24:44 by kialvare          #+#    #+#              #
#    Updated: 2017/01/05 09:25:00 by kialvare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=/bin/rm -f

LIB=libft.a

LDFLAGS=-L./libft/

LDLIBS=-lft

SRC=main.c \
	store.c \
	algo.c \
	convert.c \
	map.c \
	ft_strsplitstr.c \
	ft_arrlen.c \
	validation.c 

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
