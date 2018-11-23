# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 09:31:21 by lbarthon          #+#    #+#              #
#    Updated: 2018/11/23 10:47:46 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=@gcc
CFLAGS=-Wall -Werror -Wextra -I libft

NAME=fillit
SRCS=./srcs/main.c \
	./srcs/is_valid.c \
	./srcs/shapes_loader.c \
	./srcs/print_short_bytes.c \
	./srcs/utils.c \
	./srcs/put_up.c \
	./srcs/solver.c
OBJ=$(SRCS:.c=.o)

GENNAME=generator
GENSRCS=./gen/main.c
GENOBJ=$(GENSRCS:.c=.o)

all: lib $(NAME) $(GENNAME)

lib:
	@make -C libft

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L libft/ -lft

$(GENNAME): $(GENOBJ)
	$(CC) -o $(GENNAME) $(GENOBJ) $(CFLAGS) -L libft/ -lft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -f $(GENNAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@rm -f $(GENOBJ)

re: fclean all

.PHONY: all fclean clean re
