/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:20:33 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/13 23:51:30 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

int	start_algo(t_general *g, int ac, char **av, char **env)
{
	int		pipefd[2];
	pid_t	pip1;
	int		outfile;
	pid_t	pip2;
	int		infile;

	infile = open(av[1], O_RDONLY);
	outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 777);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pip1 = fork();
	if (pip1 == 0)
	{
		close(pipefd[0]);
		dup2(infile, 0);
		close(infile);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		start_exec(g, av, env);
	}
	else if (pip1 > 0)
	{
		pip2 = fork();
		if (pip2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			dup2(outfile, 1);
			close(outfile);
			g->i_av++;
			start_exec(g, av, env);
		}
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pip1, NULL, 0);
		waitpid(pip2, NULL, 0);
	}
	return (0);
}

// waitpid(-1, NULL, 0);
