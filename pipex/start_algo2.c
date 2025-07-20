/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:55:31 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/20 06:56:50 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

int here_doc(t_general *g, char **av)
{
    char *line;
    
    if (pipe(g->here_fd) == -1)
    {
        free_function(g);
        return (1);
    }
    while (1)
    {
        write(1, "heredoc> ", 9);
        line = get_next_line(fd[1]);
    }
    
}

int	start_algo_here_doc(t_general *g, int ac, char **av, char **env)
{
	int		pipefd[4];
	pid_t	pipes[ac - 4];
	int		nb_av;
	int		i_pipe;
	int		i;

	nb_av = 0;
	i_pipe = 0;
	pipefd[0] = open(av[1], O_RDONLY);
	if (pipefd[0] == -1)
		pipefd[0] = open("/dev/null", O_RDONLY);
	while (i_pipe < ac - 5)
	{
		if (pipe(pipefd + 2) == -1)
		{
			perror("pipe");
			return (1);
		}
		pipes[i_pipe] = fork();
		if (pipes[i_pipe] == 0)
		{
			dup2(pipefd[0], 0);
			dup2(pipefd[3], 1);
			close(pipefd[0]);
			close(pipefd[2]);
			close(pipefd[3]);
			nb_av = i_pipe + g->i_av;
			if (start_exec(g, av, env, nb_av) == 1)
			{
				free_function(g);
				exit(1);
			}
		}
		close(pipefd[0]);
		close(pipefd[3]);
		pipefd[0] = pipefd[2];
		i_pipe++;
	}
	i_pipe++;
	pipes[i_pipe] = fork();
	if (pipes[i_pipe] == 0 && i_pipe == ac - 4)
	{
		pipefd[3] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		dup2(pipefd[0], 0);
		dup2(pipefd[3], 1);
		close(pipefd[0]);
		close(pipefd[2]);
		close(pipefd[3]);
		nb_av = i_pipe + g->i_av - 1;
		if (start_exec(g, av, env, nb_av) == 1)
		{
			free_function(g);
			return (1);
		}
	}
	close(pipefd[0]);
	close(pipefd[2]);
	close(pipefd[3]);
	i = 0;
	while (i < ac - 5)
	{
		waitpid(pipes[i], NULL, 0);
		i++;
	}
	return (0);
}
