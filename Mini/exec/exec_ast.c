/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:31:30 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/24 22:52:15 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	exec_ast(t_cmd *cmd, t_general *g)
{
	int	type;

	type = cmd->type;

	if ( type == AND)
	{
        pid_t pid1;
        pid_t pid2;

        pid1 = fork();
        if (pid1 == 0)
        {
            exec_ast(cmd->left, g);
        }
        if (waitepid_and_satus(pid1) /* == err */)
        {
            return (1); /* err */
        }

        pid2 = fork();
        if (pid2 == 0)
        {
            exec_ast(cmd->right, g);
        }
        if (waitepid_and_satus(pid2) /* == err */)
        {
            return (1); /* err */
        }

        // pas sur de devoir fork a verifier;
		// if ( WAIT-- > fork-- > exec_ast(cmd->left, g) == OK exit code good)
		// {
		// 	WAIT-- > fork-- > exec_ast(cmd->right, g)
		// }
		// else
		// 	return exit_code false
	}

	else if ( type == OR)
	{

        pid_t pid1;
        pid_t pid2;

        pid1 = fork();
        if (pid1 == 0)
        {
            exec_ast(cmd->left, g);
        }
        if (waitepid_and_satus(pid1) /* == err */)
        {
            pid2 = fork();
            if (pid2 == 0)
            {
                exec_ast(cmd->right, g);
            }
            if (waitepid_and_satus(pid2) /* == err */)
            {
                return (1);/* err */
            }
        }
        else
        {
            // je sais pas comment return mais en gros je doit dire a celui qui
            // l a appler que c est bon
        }
		// if ( WAIT-- > fork-- > exec_ast(cmd->left, g) == OK )
		// {
        //     return exit_code good
		// }
		// else if( WAIT-- > fork-- > exec_ast(cmd->right, g) == OK)
			// si le premier est faux --> tester le deuxieme
        // {
        //     return exit_code good
        // }
        // else
        //     return exit_code false
	}

	else if ( type == PIPE) // normalement c'est sur 80% sa
	{
        int pipefd[2];
        pid_t pid1;
        pid_t pid2;

        pipe(pipefd);
        pid1 = fork();
        if (pid1 == 0)
        {
            close(pipefd[0]);
            dup2(pipefd[1], 1);
            close(pipefd[1]);
            exec_ast(cmd->left, g);
        }
        pid2 = fork();
        if (pid2 == 0)
        {
            close(pipefd[1]);
            dup2(pipefd[0], 0);
            close(pipefd[0]);
            exec_ast(cmd->right, g);
        }
        close(pipefd[0]);
        close(pipefd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
	}

	else if ( type == CMD)
	{
        exec_cmd(cmd, g);
	}

	else if ( type == SUBSHELL)
	{
        // renvoier dans le parsing mais on verra apres
	}
    return (0);
}

int	exec_cmd(t_cmd *cmd, t_general *g)
{
	int	i;

	i = 0;
    while (g->path[i])
    {
        g->path[i] = ft_strjoin(g->path[i], cmd->args[0]);
        i++;
    }
    // faire tout ton delire de " "
    i = 0;
    while (g->path[i] != 0)
    {
        if (access(g->path[i], F_OK) == 0)
        {
            if (access(g->path[i], X_OK) == 0)
            execve(g->path[i], cmd->args, g->env);
        }
        i++;
    }
    perror("execve");
    
    // while (g->path[i])
    // {
    //     printf("%s\n", g->path[i]);
    //     i++;
    // }
    
    return (1);
}

int	waitepid_and_satus(pid_t pipes)
{
    int status;

    waitpid(pipes, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = WTERMSIG(status);
    return (status);
}
