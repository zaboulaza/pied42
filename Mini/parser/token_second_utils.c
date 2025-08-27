/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_second_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:34:07 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/27 15:37:31 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	team_redir(t_node *tmp)
{
	if (tmp->next == NULL)
		return (1);
	if (tmp->next != NULL)
	{
		if (tmp->next->type != WORD && tmp->next->type != QUOTE)
			return (1);
	}
	return (0);
}

int	team_and_or(t_node *tmp)
{
	if (tmp->id == 0)
		return (1);
	if (tmp->next == NULL)
		return (1);
	if (tmp->next != NULL)
	{
		if (tmp->next->type != WORD && tmp->next->type != QUOTE
			&& tmp->next->type != OPEN_PAREN)
			return (1);
	}
	return (0);
}

int	team_open_parent(t_node *tmp)
{
	if (tmp->next == NULL)
		return (1);
	if (tmp->next != NULL)
	{
		if (tmp->next->type != WORD && tmp->next->type != QUOTE
			&& tmp->next->type != OPEN_PAREN)
			return (1);
	}
	return (0);
}

int	team_close_parent(t_node *tmp)
{
	if (tmp->id == 0)
		return (1);
	if (tmp->next != NULL)
	{
		if (tmp->next->type == WORD || tmp->next->type == QUOTE)
			return (1);
	}
	return (0);
}

int	team_word(t_node *tmp)
{
	if (tmp->next != NULL)
	{
		if (tmp->next->type == OPEN_PAREN)
			return (1);
	}
	return (0);
}
