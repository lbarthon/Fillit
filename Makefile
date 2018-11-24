# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 09:31:21 by lbarthon          #+#    #+#              #
#    Updated: 2018/11/24 11:19:56 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=@gcc
CFLAGS=-Wall -Werror -Wextra

NAME=fillit
SRCS=./srcs/main.c \
	./srcs/is_valid.c \
	./srcs/shapes_loader.c \
	./srcs/utils.c \
	./srcs/put_up.c \
	./srcs/solver.c
OBJ=$(SRCS:.c=.o)

all: $(NAME)

./libft/libft.a:
	@make -C libft

$(NAME): ./libft/libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L libft/ -lft
	@/bin/echo "[Fillit] Compilation ended"

%.o: %.c
	$(CC) $(CFLAGS) -I libft -c $< -o $@

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

re: fclean all

.PHONY: all fclean clean re lib
