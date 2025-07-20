/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 02:33:19 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/20 06:56:28 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <sys/types.h>

typedef struct s_general
{
	char	*path_line;
	char	**path_split;
	char	*path_join_av;
	char	**first_av;
	int		i_av;
	int		here_fd[2];
}			t_general;

void		init_function(t_general *g);
void		free_function(t_general *g);
void		free_tab(char **tab);
int			main(int ac, char **av, char **env);
int			find_path(int ac, char **av, char **env, t_general *g);
int			test_av(char **av, t_general *g);
int			put_back_slash(t_general *g);
void		rm_path(t_general *g);
int			start_algo(t_general *g, int ac, char **av, char **env);
int			start_exec(t_general *g, char **av, char **env, int i_av);
int			start_algo_here_doc(t_general *g, int ac, char **av, char **env);

#endif