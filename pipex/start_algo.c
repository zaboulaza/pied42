/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:20:33 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/22 02:48:51 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

void	child(t_general *g, int *pipefd, int i_pipe, pid_t *pipes)
{
	int	nb_av;

	pipes[i_pipe] = fork();
	if (pipes[i_pipe] == 0)
	{
		dup2(pipefd[0], 0);
		dup2(pipefd[3], 1);
		close023(pipefd);
		nb_av = i_pipe + g->i_av;
		if (start_exec(g, nb_av) == 1)
		{
			free_function(g);
			exit(1);
		}
	}
}

void	child_last(t_general *g, int *pipefd, int i_pipe, pid_t *pipes)
{
	int	nb_av;

	(void)pipes;
	pipefd[3] = open(g->av[g->ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dup2(pipefd[0], 0);
	dup2(pipefd[3], 1);
	close023(pipefd);
	nb_av = i_pipe + g->i_av;
	if (start_exec(g, nb_av) == 1)
	{
		free_function(g);
		exit(1);
	}
}

int	start_algo(t_general *g, int ac, char **av)
{
	int		pipefd[4];
	pid_t	*pipes;
	int		nb_av;
	int		i_pipe;

	pipes = malloc(sizeof(pid_t) * (ac - 3));
	if (!pipes)
		return (perror("malloc"), 1);
	i_pipe = 0;
	nb_av = 0;
	pipefd[0] = open(av[1], O_RDONLY);
	if (pipefd[0] == -1)
		pipefd[0] = open("/dev/null", O_RDONLY);
	while (i_pipe < ac - 4)
	{
		if (pipe(pipefd + 2) == -1)
			return (perror("pipe"), 1);
		child(g, pipefd, i_pipe, pipes);
		(close(pipefd[0]), close(pipefd[3]), i_pipe++);
		pipefd[0] = pipefd[2];
	}
	pipes[i_pipe] = fork();
	if (pipes[i_pipe] == 0)
		child_last(g, pipefd, i_pipe, pipes);
	return ((close023(pipefd), waitpid_(ac, pipes), free(pipes), 0));
}

void	waitpid_(int ac, pid_t *pipes)
{
	int	i;

	i = 0;
	while (i < ac - 4)
	{
		waitpid(pipes[i], NULL, 0);
		i++;
	}
}

void	close023(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[2]);
	close(pipefd[3]);
}
