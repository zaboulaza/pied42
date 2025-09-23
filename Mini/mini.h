/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:14:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/23 14:41:29 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft/libft.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

# define WORD 0
# define PIPE 1
# define OR 2
# define AND 3
# define OPEN_PAREN 4
# define CLOSE_PAREN 5
# define REDIR_IN 6
# define REDIR_OUT 7
# define REDIR_APPEND 8
# define HEREDOC 9

# define CMD 10
# define SUBSHELL 11

typedef struct s_free
{
	char			*new_str_f;
	char			*tmp_f;
	char			**arg;
	struct s_node	*new;
}					t_free;

typedef struct s_node
{
	int				type;
	char			*content;
	int				id;
	struct s_node	*next;
}					t_node;

typedef struct s_tmp
{
	char			*path;
	int				mode;
	char			**heredoc_content;
	struct s_tmp	*next;
}					t_tmp;

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
	struct s_cmd	*right;
	struct s_cmd	*left;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_general
{
	int				ac;
	char			**av;
	char			*one_line;
	char			**env;
	struct s_node	*node;
	struct s_cmd	*cmd;
	struct s_free	*free;
	struct s_tmp	*tmp;
}					t_general;
// main.c
////////////////////////////////////////////////////////////////////////////
int					main(int ac, char **av, char **env);
void				creat_struct(t_general *g, int ac, char **av, char **env);
void				free_all(t_general *g, t_tmp **tmp, t_free *f);

// ##############################  parser.c  ##############################
int					parsing_general(t_general *g, t_tmp **tmp);

// ##############################  token_first.c  #########################
int					token_first(t_general *g);
// tokenizer_utils1.c
int					quote(t_general *g);
int					bracket(t_general *g);
int and (t_general * g);

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
int					list_size(t_node *node);
// creat_list_urils2.cPIPE
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

int					token_third(t_general *g, t_tmp **tmp);
int					add_to_cmd_liste(t_cmd **cmd, t_node *node, t_tmp **tmp);
t_cmd				*new_cmd(t_node *node, t_tmp **tmp);
t_node				*next_step_cmd(t_node *node);

// token_third_utils.c
t_node				*next_step_norm_cmd(t_node *node);
int					find_cmd_type(t_node *node);
char				**find_arg(t_cmd *cmd, t_node *node, t_tmp **tmp);
char				*ft_strjoin_(char *s1, char const *s2);
char				**find_arg_norm_parent(t_node *node, t_cmd *cmd,
						t_tmp **tmp);

// token_third_utils2.c
void				free_all_(char **tab);
size_t				count_word_(char *s, char c);
char				*malloc_word_(char *str, char c);
char				**ft_split_(char *s, char c);
char				*quote_norm(char *line);
// token_third_utils3.c
int					add_to_files_liste(t_cmd *cmd, t_node *node, t_tmp **tmp);
t_files				*new_files(t_node *node);
char				**find_arg_norm(t_cmd *cmd, t_node *node, t_tmp **tmp);
int					add_to_tmp_liste(t_node *node, t_tmp **tmp);
t_tmp				*new_tmp(t_node *node);
// token_third_utils4.c
void				add_tmp_to_list(t_cmd *cmd, t_tmp **tmp);
void				remove_invalid_cmds(t_cmd **cmd_list);
int					find_arg_norm_parent2(t_node *node);
char				**heredoc_content(char *node);
char				*ft_strjoin__(char *s1, char const *s2);
// token_third_utils5.c
char				**cpy_char_tab(char **tab);
void				find_arg_norm3(t_cmd *cmd, t_tmp **tmp, t_tmp *cur);
// last_verif_parent.c
int					last_verif_parent(t_cmd *cmd);
// ##############################  token_third.c  ##########################

// creat_ast.c
t_cmd				*init_ast(t_cmd *cmd, bool mini_ast_pipe);
int					priorite(t_cmd *operateur);
t_cmd				*creat_ast_exemple(t_cmd *operateur, bool mini_ast_pipe);
t_cmd				*next_operateur_and_or(t_cmd *next_cmd);

// ##############################  exec  ##########################
// ##############################  exec  ##########################
// ##############################  exec  ##########################

// exec_ast.c
int					exec_ast(t_cmd *cmd);

// ##############################  test->need to remove  ##########################
// ##############################  test->need to remove  ##########################
// fonction de test
// void				print_list(t_node *node);
void				print_list_cmd(t_cmd *cmd);
void				free_node(t_node *node);
void				free_cmd(t_cmd *cmd);
void				clear_tmp(t_tmp **tmp);
void				print_ast(t_cmd *node, int depth);
void				print_indent(int depth);

#endif

// garbege colector

// valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes
// -q --suppressions=./ignore_leak_readline ./MINI

// ################################################################################################ #
// sl | lksadj ls < dsf > df ds | ""fdsf sdf""fds sdfafja"ajakhdf"sdkafjah | < out | > in cat > fd
// -e | (jsdahf | dfsad)
// ((date) && (whoami))

// need to do heredoc solo like : << EOF << EOF2 << EOF3
//'' read of size