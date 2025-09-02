/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_third.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:56:31 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/02 01:44:31 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	token_third(t_general *g)
{
	if (add_to_cmd_liste(&g->cmd, g->node) == 1)
		return (1);
	return (0);
}

int	add_to_cmd_liste(t_cmd **cmd, t_node *node)
{
	t_cmd	*new;
	t_cmd	*tmp;

	if (!node)
		return (0);
	while (node != NULL)
	{
		new = new_cmd(node);
		if (!new)
			return (1);
		if (!*cmd)
			*cmd = new;
		else
		{
			tmp = *cmd;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		node = next_step_cmd(node);
	}
	return (0);
}

t_cmd	*new_cmd(t_node *node)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	ft_bzero(cmd, sizeof(t_cmd));
	cmd->type = find_cmd_type(node);
	cmd->args = find_arg(cmd, node);
	cmd->next = NULL;
	return (cmd);
}

t_node	*next_step_cmd(t_node *node)
{
	if (node->type == WORD)
	{
		while (node != NULL && node->type == WORD)
		{
			node = node->next;
			while (node != NULL && (node->type >= REDIR_IN
					&& node->type <= HEREDOC))
				node = node->next;
		}
	}
	else if (node->type == OPEN_PAREN)
		node = next_step_norm_cmd(node);
	else if (node->type >= PIPE && node->type <= ESPERLUETTE)
		node = node->next;
	return (node);
}
