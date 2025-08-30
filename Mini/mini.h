/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:14:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/30 22:10:54 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft/libft.h"
# include <limits.h>
# include <readline/readline.h>
# include <stdio.h>

# define WORD 0
# define PIPE 1
# define DOUBLE_PIPE 2
# define ESPERLUETTE 3
# define OPEN_PAREN 4
# define CLOSE_PAREN 5
# define REDIR_IN 6
# define REDIR_OUT 7
# define REDIR_APPEND 8
# define HEREDOC 9

typedef struct s_general
{
	int				ac;
	char			**av;
	char			*one_line;
	struct s_node	*node;
	struct s_cmd	*cmd;
}					t_general;

// token
typedef struct s_node
{
	int				type;
	char			*content;
	int				id;
	struct s_node	*next;
}					t_node;

// regroupement
typedef struct s_files
{
	char			*path;
	int mode; // < / << / > / >>
	char			**heredoc_content;
	struct s_files	*next;
}					t_files;

typedef struct s_cmd
{
	int type; // cmd / subshell () / pipe / et / ou
	char			**args;
	t_files			*files;
	struct s_cmd	*next;
}					t_cmd;

// main.c
////////////////////////////////////////////////////////////////////////////
int					main(int ac, char **av, char **env);
void				creat_struct(t_general *g, int ac, char **av);
void				free_all(t_general *g);

// ##############################  parser.c  ##############################
int					parsing_general(t_general *g);

// ##############################  token_first.c  #########################
int					token_first(t_general *g);
// tokenizer_utils1.c
int					bracket(t_general *g);
int					quote(t_general *g);
int					esperluette(t_general *g);

// ##############################  creat_list.c  ###########################
int					add_to_liste(t_node **node, char *line);
t_node				*new_node(char *line);
char				*next_step(char *line);
int					next_step_norm(char *line);
// creat_list_urils.c
int					find_type(char *line);
int					ispacce(char c);
char				*find_content(char *line);
int					find_content_norm(char *line);
void				list_size(t_node *node);

// ##############################  token_second.c  ##########################
// parser la list
int					token_second(t_node **node);
int					team_redir(t_node *tmp);
int					team_and_or(t_node *tmp);
int					team_open_parent(t_node *tmp);
int					team_close_parent(t_node *tmp);
int					team_word(t_node *tmp);
int					token_second_norme(t_node *tmp);

// ##############################  token_third.c  ##########################

int					token_third(t_general *g);
int					add_to_cmd_liste(t_cmd **cmd, t_node *node);
int					new_cmd(t_node *node);

// fonction de test
void				print_list(t_node *node);

#endif