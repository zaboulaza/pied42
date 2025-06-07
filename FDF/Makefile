# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 17:02:03 by nsmail            #+#    #+#              #
#    Updated: 2025/06/07 12:37:41 by nsmail           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# Fichiers sources
SRCS = 	main.c parsing/parsing.c parsing/parsing_2.c src/ramplisage.c \
		trace_ligne.c trace_ligne2.c

# Bibliothèques
LIBFT_DIR = libft
GNL_DIR = get_next_line
MLX_DIR = mlx

MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/get_next_line.a

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME) -g3

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re