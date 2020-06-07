# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkhodizo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/06 15:57:52 by gkhodizo          #+#    #+#              #
#    Updated: 2020/06/07 16:29:20 by gkhodizo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

BUFF = -DBUFFER_SIZE=1

INCLUDE = ../get_next_line.h color.h

# MAIN FILES:
MAIN_SRCS = ../get_next_line.c ../get_next_line_utils.c ./color.c ./test.c ./main.c 
MAIN_OBJ = ./get_next_line.o ./get_next_line_utils.o ./color.o ./test.o ./main.o

.SILENT:

all: $(NAME)
	@echo Compiling $(NAME)...

$(NAME): $(MAIN_OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(BUFF) $(MAIN_SRCS) -o $(NAME)

$(MAIN_OBJ):
	$(CC) $(CFLAGS) $(BUFF) -c $(MAIN_SRCS)

clean:
	@/bin/rm -f $(MAIN_OBJ)
	@echo Deleting object files...

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo Deleting $(NAME)...

re: fclean all

.PHONY: all clean fclean re bonus