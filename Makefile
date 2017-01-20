# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kialvare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 09:24:44 by kialvare          #+#    #+#              #
#    Updated: 2017/01/19 15:25:48 by kialvare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

CC=gcc

FLAGS=-Wall -Wextra -Werror

RM=/bin/rm -f

LIB=libft.a

LDFLAGS= -L libft/

LDLIBS=-lft

# INCLUDES = -I $(LIB_PATH) -I ./includes

SRC=src/main.c \
	src/store.c \
	src/algo.c \
	src/map.c \
	src/ft_arrlen.c \
	src/ft_strsplitstr.c \
	src/validation.c 

all: $(NAME)

$(LIB):
	make -C libft/

OBJ := $(patsubst %.c,%.o,$(SRC))

# obj:
# 	@mkdir obj

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# obj/%o: srcs/%.c ./includes/*.h
# 	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)
	# @rmdir -p obj
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re

# NAME = fillit

# CC = gcc

# FLAGS = -Wall -Werror -Wextra

# LIB_PATH = libft/

# LIB = $(LIB_PATH)libft.a

# LIB_LINK = -L $(LIB_PATH) -lft

# INCLUDES = -I $(LIB_PATH) -I ./includes

# SRC =	src/main.c \
# 		src/store.c \
# 		src/algo.c \
# 		src/convert.c \
# 		src/map.c \
# 		src/ft_arrlen.c \
# 		src/ft_strsplitstr.c \
# 		src/validation.c 

# OBJ = $(SRC:src/%.c=obj/%.o)

# all: obj $(NAME)

# $(NAME): $(LIB) $(OBJ)
# 	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)

# $(LIB):
# 	@make -C $(LIB_PATH)

# obj:
# 	@mkdir -p obj

# obj/%o: srcs/%.c ./includes/*.h
# 	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

# clean:
# 	@rm -f $(OBJS)
# 	@rm -rf obj

# fclean: clean
# 	@rm -f $(NAME)
# 	@make -C $(LIB_PATH) fclean

# re: fclean all

# .PHONY: all clean fclean re
