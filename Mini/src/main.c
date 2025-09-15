/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:24:27 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/15 22:19:46 by zaboulaza        ###   ########.fr       */
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
			free_all(&g, &g.tmp, g.free);
			printf("exit\n");
			break ;
		}
		if (*g.one_line)
		{
			if (parsing_general(&g, &g.tmp) == 1)
			{
				free_all(&g, &g.tmp, g.free);
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
	g->free = ft_calloc(1, sizeof(t_free));
}

void	free_all(t_general *g, t_tmp **tmp, t_free *f)
{
	(void)tmp;
	if (g)
	{
		if (g->one_line)
		{
			free(g->one_line);
			g->one_line = NULL;
		}
		if (g->node)
		{
			free_node(g->node);
			g->node = NULL;
		}
		if (g->cmd)
		{
			free_cmd(g->cmd);
			g->cmd = NULL;
		}
	}
	if (f)
	{
		if (f->new_str_f)
		{
			free(f->new_str_f);
			f->new_str_f = NULL;
		}
		if (f->tmp_f)
		{
			free(f->tmp_f);
			f->tmp_f = NULL;
		}
		if (f->arg)
		{
			free_all_(f->arg);
			f->arg = NULL;
		}
		free(f);
		f = NULL;
	}
}

void	free_node(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		if (node->content)
			free(node->content);
		free(node);
		node = tmp;
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_files	*file_tmp;
	t_files	*file_next;

	while (cmd)
	{
		if (cmd->args)
			free_all_(cmd->args);
		file_tmp = cmd->files;
		while (file_tmp)
		{
			file_next = file_tmp->next;
			if (file_tmp->path)
				free(file_tmp->path);
			free(file_tmp);
			file_tmp = file_next;
		}
		tmp = cmd->next;
		free(cmd);
		cmd = tmp;
	}
}

void	clear_tmp(t_tmp **tmp)
{
	t_tmp	*cur;
	t_tmp	*next;

	cur = *tmp;
	while (cur)
	{
		next = cur->next;
		free(cur->path);
		free(cur);
		cur = next;
	}
	*tmp = NULL;
}


void	print_list_cmd(t_cmd *cmd)
{
	int		i;
	t_files	*tmp_files;
	int		j;

	while (cmd != NULL)
	{
		printf("type = %d\n", cmd->type);
		i = 0;
		if (cmd->args != NULL)
		{
			while (cmd->args[i] != NULL)
			{
				printf("{cmd} // arg = %s\n", cmd->args[i]);
				i++;
			}
		}
		tmp_files = cmd->files;
		while (tmp_files != NULL)
		{
			printf("{files} // path = %s\n", tmp_files->path);
			printf("{files} // mode = %d\n", tmp_files->mode);
			if (tmp_files->heredoc_content != NULL)
			{
				j = 0;
				printf("{heredoc} content:\n");
				while (tmp_files->heredoc_content[j] != NULL)
				{
					printf("  [%d] %s\n", j, tmp_files->heredoc_content[j]);
					j++;
				}
			}
			
			tmp_files = tmp_files->next;
		}
		printf("\n");
		cmd = cmd->next;
	}
}

// void	print_list(t_node *node)
// {
// 	while (node != NULL)
// 	{
// 		printf("{LIST} type = %d\n", node->type);
// 		printf("{LIST} content = %s\n", node->content);
// 		printf("\n");
// 		node = node->next;
// 	}
// }