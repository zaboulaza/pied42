/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_third.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:56:31 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/30 22:26:01 by nsmail           ###   ########.fr       */
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
		node = node->next;
	}
}

t_cmd	*new_cmd(t_node *node)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	ft_bzero(cmd, sizeof(t_cmd));
	cmd->type = find_cmd_type(node);
	return (cmd);
}

int	find_cmd_type(t_cmd *node)
{
	if (node->type == WORD)
		return (WORD);
	else if (node->type == )
		return (0);
}
