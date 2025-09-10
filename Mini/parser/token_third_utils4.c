/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_third_utils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:55:59 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/10 21:11:52 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	add_tmp_to_list(t_cmd *cmd, t_tmp **tmp)
{
	t_tmp	*tmp_;
	t_files	*new;
	t_files	*last;

	tmp_ = *tmp;
	while (tmp_)
	{
		new = malloc(sizeof(t_files));
		ft_bzero(new, sizeof(t_files));
		new->mode = tmp_->mode;
		new->path = ft_strdup(tmp_->path);
		new->next = NULL;
		if (cmd->files == NULL)
			cmd->files = new;
		else
		{
			last = cmd->files;
			while (last->next)
				last = last->next;
			last->next = new;
		}
		tmp_ = tmp_->next;
	}
	clear_tmp(tmp);
}

void	remove_invalid_cmds(t_cmd **cmd_list)
{
	t_cmd	*current;
	t_cmd	*prev;
	t_cmd	*next;

	current = *cmd_list;
	prev = NULL;
	while (current)
	{
		next = current->next;
		if (current->type == 100)
		{
			if (prev)
				prev->next = next;
			else
				*cmd_list = next;
			free(current);
			current = next;
		}
		else
		{
			prev = current;
			current = next;
		}
	}
}
