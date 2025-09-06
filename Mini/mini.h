/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:14:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/06 14:55:13 by zaboulaza        ###   ########.fr       */
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

# define CMD 10
# define SUBSHELL 11

typedef struct s_general
{
	int				ac;
	char			**av;
	char			*one_line;
	struct s_node	*node;
	struct s_cmd	*cmd;
	struct s_free	*free;
}					t_general;

typedef struct s_free
{
}					t_free;

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
	int				mode;
	char			**heredoc_content;
	struct s_files	*next;
}					t_files;

typedef struct s_cmd
{
	int				type;
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
int					quote(t_general *g);
int					bracket(t_general *g);
int					esperluette(t_general *g);

// ##############################  creat_list.c  ###########################
int					add_to_liste(t_node **node, char *line);
t_node				*new_node(char *line);
char				*next_step(char *line);
int					next_step_norm(char *line);
int					next_step_norm2(char *line);
// creat_list_urils1.c
int					find_type(char *line);
int					ispacce(char c);
char				*find_content(char *line);
int					find_content_norm(char *line);
void				list_size(t_node *node);
// creat_list_urils2.c
int					find_content_norm1(char *line);

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
t_cmd				*new_cmd(t_node *node);
t_node				*next_step_cmd(t_node *node);

// token_third_utils.c
t_node				*next_step_norm_cmd(t_node *node);
int					find_cmd_type(t_node *node);
char				**find_arg(t_cmd *cmd, t_node *node);
char				*ft_strjoin_(char *s1, char const *s2);
char				**find_arg_norm_parent(t_node *node);

// token_third_utils2.c
void				free_all_(char **tab);
size_t				count_word_(char *s, char c);
char				*malloc_word_(char *str, char c);
char				**ft_split_(char *s, char c);
char				*quote_norm(char *line);
// token_third_utils3.c
int					add_to_files_liste(t_cmd *cmd, t_node *node);
t_files				*new_files(t_node *node);
char				**find_arg_norm(t_cmd *cmd, t_node *node);

// fonction de test
void				print_list(t_node *node);
void				print_list_cmd(t_cmd *cmd);

#endif

// garbege colector

// valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes
// -q --suppressions=./ignore_leak_readline ./MINI

// ################################################################################################ #
// sl | lksadj f? < dsf > df ds | ""fdsf sdf""fds fddf sdfafja"ajakhdf"sdkafjah (jsdahf | dfsad) good
