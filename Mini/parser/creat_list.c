/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:42:26 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/23 18:53:07 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mini.h"

int	add_to_liste(t_node **node, char *line)
{
	t_node	*new;
	t_node	*tmp;

	while (*line != '\0')
	{
		new = new_node(line);
		if (!new)
			return (1);
		if (!*node)
		{
			*node = new;
			return (0);
		}
		tmp = *node;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		printf("line = %s\n", line);
		line = (line + 4);
		printf("line = %s\n", line);
		line = next_step(line);
		printf("line = %s\n", line);
		printf("see\n");
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
	char	special[7] = "|&()<>";

	if (ft_strchr(special, *line) != NULL)
	{
		if ((*line == '|' && *(line + 1) == '|') || (*line == '&' && *(line
					+ 1) == '&'))
			return (line + 2);
		if (*line == '|' && *(line + 1) != '|')
			return (line + 1);
		if ((*line == '(') || (*line == ')') || (*line == ')'))
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
				|| ispacce(*line) != 1))
			line++;
	}
	return (line);
}
