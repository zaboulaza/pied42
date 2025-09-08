/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:17:00 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/08 15:14:33 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	find_type(char *line)
{
	if (*line == '|' && *(line + 1) != '|')
		return (PIPE);
	if (*line == '|' && *(line + 1) == '|')
		return (DOUBLE_PIPE);
	if (*line == '&' && *(line + 1) == '&')
		return (ESPERLUETTE);
	if (*line == '(')
		return (OPEN_PAREN);
	if (*line == ')')
		return (CLOSE_PAREN);
	if (*line == '<' && *(line + 1) != '<')
		return (REDIR_IN);
	if (*line == '>' && *(line + 1) != '>')
		return (REDIR_OUT);
	if (*line == '<' && *(line + 1) == '<')
		return (HEREDOC);
	if (*line == '>' && *(line + 1) == '>')
		return (REDIR_APPEND);
	return (WORD);
}

char	*find_content(char *line)
{
	int		lenght;
	char	*special;
	char	quote;

	special = "|&()<>";
	lenght = 0;
	if (line[lenght] == '"' || line[lenght] == 39)
	{
		quote = line[lenght++];
		while (line[lenght] && line[lenght] != quote)
			lenght++;
		if (line[lenght + 1])
			lenght++;
		while (line[lenght] != '\0' && ispacce(line[lenght]) != 1)
			lenght++;
	}
	else if (ft_strchr(special, *line) != NULL)
		return (ft_substr(line, 0, find_content_norm(line)));
	else
	{
		lenght += find_content_norm1(line);
		while (ispacce(line[lenght]) == 1)
			lenght++;
	}
	return (ft_substr(line, 0, lenght));
}

int	find_content_norm(char *line)
{
	if (*line == '|' && *(line + 1) != '|')
		return (1);
	if ((*line == '|' && *(line + 1) == '|') || (*line == '&' && *(line
				+ 1) == '&'))
		return (2);
	if ((*line == '(') || (*line == ')'))
		return (1);
	if ((*line == '<' && *(line + 1) != '<') || (*line == '>' && *(line
				+ 1) != '>'))
		return (1);
	if ((*line == '<' && *(line + 1) == '<') || (*line == '>' && *(line
				+ 1) == '>'))
		return (2);
	return (0);
}

int	ispacce(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	list_size(t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		node->id = i;
		i++;
		node = node->next;
	}
}
