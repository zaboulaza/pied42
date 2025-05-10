# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/10 16:44:48 by zaboulaza         #+#    #+#              #
#    Updated: 2025/05/10 16:58:28 by zaboulaza        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextligne.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
EXEC = main

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiled $<\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME) $(EXEC)

re: fclean all