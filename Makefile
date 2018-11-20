# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 09:31:21 by lbarthon          #+#    #+#              #
#    Updated: 2018/11/20 09:22:43 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=@gcc
CFLAGS=-Wall -Werror -Wextra

LIB=./libft/libft.a

NAME=fillit
FILES=./srcs/main.c
OBJ=$(FILES:.c=.o)

GENNAME=generator
GENFILES=./gen/main.c
GENOBJ=$(GENFILES:.c=.o)

all: lib $(NAME) $(GENNAME)

lib:
	@make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(GENNAME): $(GENOBJ)
	$(CC) $(CFLAGS) -o $(GENNAME) $(GENOBJ) $(LIB)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(GENNAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(GENOBJ)

re: fclean all

.PHONY: all fclean clean re
