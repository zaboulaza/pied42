# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/21 12:55:13 by nsmail            #+#    #+#              #
#    Updated: 2025/08/22 16:01:26 by nsmail           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = MINI

# Fichiers source
SRCS = src/main.c \
       parser/parser.c \
       parser/tokenizer.c \
       parser/creat_list.c \
       parser/tokenizer_utils1.c

# Objets correspondants
OBJS = $(SRCS:.c=.o)

# Compilateur & flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# Librairies (à adapter selon ton projet)
LIBFT = libft/libft.a
READLINE = -lreadline

# Compilation de base
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

# Compilation générique des .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règles de nettoyage
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re