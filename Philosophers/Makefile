# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 22:09:56 by nsmail            #+#    #+#              #
#    Updated: 2025/08/17 22:11:07 by nsmail           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Philosophers

SRCS = main.c parsing_general.c function_utils.c start_code.c \
       function_utils_2.c function_utils_3.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# compilation de base
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# règle générique pour compiler les .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# -lpthread