/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:24:54 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/17 17:01:39 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_cmd	*creat_ast(t_cmd *cmd)
{
	t_cmd	*cmd2;

	// cmd2 = cmd;
	// if (!cmd)
	// 	return (NULL);
	// if (cmd2->next == NULL)
	//     return cmd
	// find_first_special(cmd2);



	if (/* cmd == NULL */)
	{
		// return NULL
	}

    
	if (/* cmd->next == NULL */)
	{
		// return (cmd)
	}
	else
	{
		// cmd->next->left == cmd
		// cmd = cmd->next;
	}

	// verif si il y a un autre operateur
    if (/* pas d'autre operateur */)
    {
        //  cmd->right = cmd->next;
        // return (cmd);
    }

	while (/* cmd->next->next != NULL */)
    {
        // verif si il y a un autre ope ( cmd->next->next )
		// si oui verifier ses permission par raport a moi
		if (/* j'ai plus de permission alors ou c'est les meme ( | )*/)
		{
            // cmd->right = cmd->next;
			// cmd = cmd->next;
		}
		else /* ( || , && ) */
		{
            // cmd->right = cmd->next->next;
            // cmd->next->next->left = cmd->next;
        }

        if (/* cmd->next->next->next->next == NULL */)
        {
            // cmd->next->next->right = cmd->next->next->next;
            // break;
        }
        // cmd = cmd->next->next
    }
}

// void