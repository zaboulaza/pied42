/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:20:33 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/18 02:30:56 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"
// #include <sys/wait.h>

// int	start_algo(t_general *g, int ac, char **av, char **env)
// {
// 	int		pipefd[4];
// 	pid_t	pip1;
// 	pid_t	pip2;

// 	pipefd[0] = open(av[1], O_RDONLY);
// 	pipefd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 777);
// 	if (pipefd[0] == -1 || pipefd[1] == -1)
// 		return (1);
// 	if (pipe(pipefd + 2))
// 	{
// 		perror("pipe");
// 		return (1);
// 	}
// 	pip1 = fork();
// 	if (pip1 == 0)
// 	{
// 		dup2(pipefd[0], 0);
// 		dup2(pipefd[3], 1);
// 		close(pipefd[0]);
// 		close(pipefd[2]);
// 		close(pipefd[3]);
// 		close(pipefd[1]);
// 		if (start_exec(g, av, env) == 1)
// 		{
// 			free_function(g);
// 			exit(1);
// 		}
// 	}
// 	pip2 = fork();
// 	if (pip2 == 0)
// 	{
// 		dup2(pipefd[2], 0);
// 		dup2(pipefd[1], 1);
// 		close(pipefd[3]);
// 		close(pipefd[2]);
// 		close(pipefd[1]);
// 		close(pipefd[0]);
// 		g->i_av++;
// 		if (start_exec(g, av, env) == 1)
// 		{
// 			free_function(g);
// 			exit(1);
// 		}
// 	}
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	close(pipefd[2]);
// 	close(pipefd[3]);
// 	waitpid(pip1, NULL, 0);
// 	waitpid(pip2, NULL, 0);
// 	return (0);
// }

// int	start_algo(t_general *g, int ac, char **av, char **env)
// {
// 	int pipefd[4];
// 	pid_t pipes[ac - 3];
// 	int i_pipe = 0;
// 	int i = 0;

// 	pipefd[0] = open(av[1], O_RDONLY);
// 	// pipefd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 777);
// 	while (i_pipe <= ac - 4)
// 	{
// 		if (pipe(pipefd + 2) == -1)
// 		{
// 			perror("pipe");
// 			return (1);
// 		}
// 		pipes[i_pipe] = fork();
// 		if (pipes[i_pipe] == 0)
// 		{
// 			close(pipefd[1]);
// 			dup2(pipefd[0], 0);
// 			close(pipefd[0]);
// 			dup2(pipefd[3], 1);
// 			close(pipefd[3]);
// 			if (start_exec(g, av, env) == 1)
// 			{
// 				free_function(g);
// 				exit(1);
// 			}
// 		}
// 		pipefd[0] = pipefd[2];
// 		close(pipefd[1]);
// 		close(pipefd[3]);
// 		i_pipe++;
// 	}
// 	if (i_pipe = ac - 3)
// 	{
// 		pipefd[3] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 		close(pipefd[1]);
// 		dup2(pipefd[0], 0);
// 		close(pipefd[0]);
// 		dup2(pipefd[3], 1);
// 		close(pipefd[3]);
// 		close(pipefd[2]);
// 		if (start_exec(g, av, env) == 0)
// 		{
// 			free_function(g);
// 			return (1);
// 		}
// 	}
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	close(pipefd[2]);
// 	close(pipefd[3]);
// 	while (i < ac - 3)
// 	{
// 		waitpid(pipes[i], NULL, 0);
// 		i++;
// 	}
// 	return (0);
// }