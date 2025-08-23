# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/21 12:55:13 by nsmail            #+#    #+#              #
#    Updated: 2025/08/23 02:28:39 by zaboulaza        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = MINI

# Fichiers source
SRCS = src/main.c \
       parser/parser.c \
       parser/tokenizer.c \
       parser/creat_list.c \
       parser/tokenizer_utils1.c

# Dossier des objets
OBJDIR = obj

# Objets correspondants dans obj/
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Compilateur & flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# Librairies
LIBFT = libft/libft.a
READLINE = -lreadline

# Compilation de base
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

# Règle générique pour compiler .c → .o dans obj/
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)   # crée le dossier si besoin
	$(CC) $(CFLAGS) -c $< -o $@

# Règles de nettoyage
clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re