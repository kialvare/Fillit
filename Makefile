# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kialvare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 09:24:44 by kialvare          #+#    #+#              #
#    Updated: 2017/01/24 18:32:23 by kialvare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

CC=gcc

FLAGS=-Wall -Wextra -Werror

RM=/bin/rm -f

LIB=libft.a

LDFLAGS= -L libft/

LDLIBS=-lft

SRC=src/main.c \
	src/store.c \
	src/algo.c \
	src/map.c \
	src/validation.c 

all: $(NAME)

$(LIB):
	make -C libft/

OBJ := $(patsubst %.c,%.o,$(SRC))

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) -fsanitize=address

clean:
	$(RM) $(OBJ)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re

