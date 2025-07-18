/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:20:33 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/18 06:17:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

int	start_algo(t_general *g, int ac, char **av, char **env)
{
	int		pipefd[4];
	pid_t	pipes[ac - 3];
	int		nb_av;
	int		i_pipe;
	int		i;

	nb_av = 0;
	i_pipe = 0;
	i = 0;
	pipefd[0] = open(av[1], O_RDONLY);
	while (i_pipe < ac - 4)
	{
		if (pipe(pipefd + 2) == -1)
		{
			perror("pipe");
			return (1);
		}
		pipes[i_pipe] = fork();
		if (pipes[i_pipe] == 0)
		{
			pipefd[1] = -1;
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			dup2(pipefd[3], 1);
			close(pipefd[3]);
			nb_av = i_pipe + g->i_av;
			if (start_exec(g, av, env, nb_av) == 1)
			{
				free_function(g);
				exit(1);
			}
		}
		i_pipe++;
		pipefd[0] = pipefd[2];
		pipefd[1] = -1;
		close(pipefd[1]);
		close(pipefd[3]);
		// close(pipefd[2]);
	}
	i_pipe++;
	pipes[i_pipe] = fork();
	if (pipes[i_pipe] == 0 && i_pipe == ac - 3)
	{
		pipefd[3] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		dup2(pipefd[3], 1);
		close(pipefd[3]);
		close(pipefd[2]);
		nb_av = i_pipe + g->i_av - 1;
		if (start_exec(g, av, env, nb_av) == 1 )
		{
			free_function(g);
			return (1);
		}
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(pipefd[2]);
	close(pipefd[3]);
	while (i <= ac - 3)
	{
		waitpid(pipes[i], NULL, 0);
		i++;
	}
	return (0);
}

// int	start_algo(t_general *g, int ac, char **av, char **env)
// {
// 	int		pipefd[2];
// 	pid_t	pip1;
// 	int		outfile;
// 	pid_t	pip2;
// 	int		infile;

// 	infile = open(av[1], O_RDONLY);
// 	if (infile == -1)
// 		return (1);
// 	outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (outfile == -1)
// 		return (1);
// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		return (1);
// 	}
// 	pip1 = fork();
// 	if (pip1 == 0)
// 	{
// 		close(pipefd[0]);
// 		dup2(infile, 0);
// 		close(infile);
// 		dup2(pipefd[1], 1);
// 		close(pipefd[1]);
// 		close(outfile);
// 		if (start_exec(g, av, env) == 1)
// 		{
// 			close(outfile);
// 			free_function(g);
// 			exit(1);
// 		}
// 	}
// 	else if (pip1 > 0)
// 	{
// 		pip2 = fork();
// 		if (pip2 == 0)
// 		{
// 			close(pipefd[1]);
// 			dup2(pipefd[0], 0);
// 			close(pipefd[0]);
// 			dup2(outfile, 1);
// 			close(outfile);
// 			close(infile);
// 			g->i_av++;
// 			if (start_exec(g, av, env) == 1)
// 			{
// 				close(infile);
// 				free_function(g);
// 				exit(1);
// 			}
// 		}
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		close(outfile);
// 		close(infile);
// 		waitpid(pip1, NULL, 0);
// 		waitpid(pip2, NULL, 0);
// 	}
// 	return (0);
// }

// waitpid(-1, NULL, 0);
