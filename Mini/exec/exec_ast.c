/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:52:52 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/23 20:13:10 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../mini.h"

int	exec_ast(t_cmd *cmd)
{
	int	type;
    
	type = cmd->type;
    
	if (/* type == AND */)
	{
        pid_t pid1;
        pid_t pid2;

        pid1 = fork();
        if (pid1 == 0)
        {
            exec_ast(cmd->left);
        }
        if (waitepid_and_satus(pid1) == err)
        {
            return errr
        }
        
        pid2 = fork();
        if (pid2 == 0)
        {
            exec_ast(cmd->right);
        }
        if (waitepid_and_satus(pid2) == err)
        {
            return errr
        }

        // pas sur de devoir fork a verifier;
		// if ( WAIT-- > fork-- > exec_ast(cmd->left) == OK exit code good)
		// {
		// 	WAIT-- > fork-- > exec_ast(cmd->right)
		// }
		// else
		// 	return exit_code false
	}
    
	else if (/* type == OR */)
	{

        pid_t pid1;
        pid_t pid2;

        pid1 = fork();
        if (pid1 == 0)
        {
            exec_ast(cmd->left);
        }
        if (waitepid_and_satus(pid1) == err)
        {
            pid2 = fork();
            if (pid2 == 0)
            {
                exec_ast(cmd->right);
            }
            if (waitepid_and_satus(pid2) == err)
            {
                return err
            }
        }
        else 
        {
            je sais pas comment return mais en gros je doit dire a celui qui 
            l a appler que c est bon
        }
		// if ( WAIT-- > fork-- > exec_ast(cmd->left) == OK )
		// {
        //     return exit_code good
		// }
		// else if( WAIT-- > fork-- > exec_ast(cmd->right) == OK) // si le premier est faux --> tester le deuxieme
        // {
        //     return exit_code good
        // }
        // else
        //     return exit_code false
	}

	else if (/* type == PIPE */) // normalement c'est sur 80% sa 
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
            exec_ast(cmd->left);
        }
        pid2 = fork();
        if (pid2 == 0)
        {
            close(pipefd[1]);
            dup2(pipefd[0], 0);
            exec_ast(cmd->right);
        }
        close(pipefd[0]);
        close(pipefd[1]);
        waitpid(pid1);
        waitpid(pid2);
	}

	else if (/* type == CMD */)
	{
        // si c'est une cmd l'executer simplement
        exec_cmd()
	}

	else if (/* type == SUBSHELL */)
	{
        // renvoier dans le parsing mais on verra apres
	}
}

// void pipe_function()
// {

// }

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
