/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:42:26 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/27 15:36:11 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	add_to_liste(t_node **node, char *line)
{
	t_node	*new;
	t_node	*tmp;

	while (*line != '\0')
	{
		while (*line && ispacce(*line) == 1)
			line++;
		if (!*line)
			return (0);
		new = new_node(line);
		if (!new)
			return (1);
		if (!*node)
			*node = new;
		else
		{
			tmp = *node;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		line = next_step(line);
	}
	list_size(*node);
	return (0);
}

t_node	*new_node(char *line)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->type = find_type(line);
	node->content = find_content(line);
	node->next = NULL;
	return (node);
}

char	*next_step(char *line)
{
	char	*special;

	special = "|&()<>";
	while (ispacce(*line) == 1)
		line++;
	if (*line == '"')
	{
		line++;
		while (*line && *line != '"')
			line++;
		if (*(line + 1))
			line++;
	}
	else if (ft_strchr(special, *line) != NULL)
		return (line + next_step_norm(line));
	else
	{
		while (*line && (ft_strchr(special, *line) == NULL
				&& ispacce(*line) != 1))
			line++;
	}
	while (*line && ispacce(*line) == 1)
		line++;
	return (line);
}

int	next_step_norm(char *line)
{
	if ((*line == '|' && *(line + 1) == '|') || (*line == '&' && *(line
				+ 1) == '&'))
		return (2);
	if ((*line == '|' && *(line + 1) != '|') || (*line == '(' || *line == ')'))
		return (1);
	if ((*line == '<' && *(line + 1) == '<') || (*line == '>' && *(line
				+ 1) == '>'))
		return (2);
	if ((*line == '<' && *(line + 1) != '<') || (*line == '>' && *(line
				+ 1) != '>'))
		return (1);
	return (0);
}
