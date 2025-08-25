/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:42:26 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/25 16:35:11 by nsmail           ###   ########.fr       */
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
	printf("NEW NODE: type=%d, content='%s'\n", node->type, node->content);
	return (node);
}

char	*next_step(char *line)
{
	char	special[7] = "|&()<>";

	while (ispacce(*line) == 1)
		line++;
    
	if (ft_strchr(special, *line) != NULL)
	{
		if ((*line == '|' && *(line + 1) == '|') || (*line == '&' && *(line
					+ 1) == '&'))
			return (line + 2);
		if ((*line == '|' && *(line + 1) != '|') || (*line == '('
				|| *line == ')'))
			return (line + 1);
		if ((*line == '<' && *(line + 1) == '<') || (*line == '>' && *(line
					+ 1) == '>'))
			return (line + 2);
		if ((*line == '<' && *(line + 1) != '<') || (*line == '>' && *(line
					+ 1) != '>'))
			return (line + 1);
	}
	else
	{
		while (*line && (ft_strchr(special, *line) == NULL
				&& ispacce(*line) != 1))
			line++;
	}
	while (ispacce(*line) == 1)
		line++;
	return (line);
}
