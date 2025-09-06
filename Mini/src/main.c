/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:24:27 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/05 23:54:40 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	main(int ac, char **av, char **env)
{
	t_general	g;

	(void)env;
	creat_struct(&g, ac, av);
	while (1)
	{
		g.one_line = readline("mini> ");
		if (!g.one_line)
		{
			printf("exit\n");
			break ;
		}
		if (*g.one_line)
		{
			if (parsing_general(&g) == 1)
			{
				free_all(&g);
				return (1);
			}
			// print_list(g.node);
			print_list_cmd(g.cmd);
		}
	}
	return (0);
}

void	creat_struct(t_general *g, int ac, char **av)
{
	ft_memset(g, 0, sizeof(t_general));
	g->ac = ac;
	g->av = av;
	g->node = NULL;
}

void	free_all(t_general *g)
{
	if (g->one_line)
		free(g->one_line);
}

void	print_list_cmd(t_cmd *cmd)
{
	int	i;

	while (cmd != NULL)
	{
		printf("type = %d\n", cmd->type);
		i = 0;
		if (cmd->args)
		{
			while (cmd->args[i])
			{
				printf("{cmd} // arg = %s\n", cmd->args[i]);
				i++;
				if (!cmd->args[i])
					printf("{cmd} // arg = %s\n", cmd->args[i]);
			}
		}
		if (cmd->files)
		{
			while (cmd->files)
			{
				printf("{files} // path = %s\n", cmd->files->path);
				printf("{files} // mode = %d\n", cmd->files->mode);
				cmd->files = cmd->files->next;
			}
		}
		printf("\n");
		cmd = cmd->next;
	}
}

// void	print_list(t_node *node)
// {
// 	while (node != NULL)
// 	{
// 		printf("{LIST} id = %d\n", node->id);
// 		printf("{LIST} type = %d\n", node->type);
// 		printf("{LIST} content = %s\n", node->content);
// 		printf("\n");
// 		node = node->next;
// 	}
// }
