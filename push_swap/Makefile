# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 02:32:42 by nsmail            #+#    #+#              #
#    Updated: 2025/07/02 18:20:39 by nsmail           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	main.c parcing_base.c creat_stack.c swap.c push.c rotate.c \
reverse_rotate.c index_median.c start_algo.c target.c nb_cout.c \
put_first.c find_top.c push_a.c good_format_at_start.c sort_5.c 

LIBFT_DIR = libft
# GNL_DIR = get_next_line

LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re