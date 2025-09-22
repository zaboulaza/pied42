/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:52:52 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/22 20:20:40 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../mini.h"

// int	exec_ast(t_cmd *cmd)
// {
// 	int	type;

// 	type = cmd->type;
    
// 	if (/* type == AND */)
// 	{
// 		if ( WAIT-- > fork-- > exec_ast(cmd->left) == OK exit code good)
// 		{
// 			WAIT-- > fork-- > exec_ast(cmd->right)
// 		}
// 		else
// 			return exit_code false
// 	}
    
// 	else if (/* type == OR */)
// 	{
// 		if ( WAIT-- > fork-- > exec_ast(cmd->left) == OK )
// 		{
//             return exit_code good
// 		}
// 		else if( WAIT-- > fork-- > exec_ast(cmd->right) == OK) // si le premier est faux --> tester le deuxieme
//         {
//             return exit_code good
//         }
//         else
//             return exit_code false
// 	}
    
// 	else if (/* type == PIPE */)
// 	{
//         // ptn j'ai zape comment faire tout le delire de pipe fd et les histoir de fork etc
       
// 	}
    
// 	else if (/* type == CMD */)
// 	{
//         // si c'est une cmd l'executer simplement
//         exec_cmd()
// 	}
    
// 	else if (/* type == SUBSHELL */)
// 	{
//         // renvoier dans le parsing mais on verra apres
// 	}
// }
