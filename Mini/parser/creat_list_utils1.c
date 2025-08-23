/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:17:00 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/23 22:59:51 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	find_type(char *line)
{
	while (ispacce(*line) == 1)
		line++;
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
	char	special[7] = "|&()<>";

	lenght = 0;
	while (ispacce(*line) == 1)
		line++;
	if (ft_strchr(special, *line) != NULL)
	{
		if (*line == '|' && *(line + 1) != '|')
			return (ft_substr(line, 0, 1));
		if ((*line == '|' && *(line + 1) == '|') || (*line == '&' && *(line
					+ 1) == '&'))
			return (ft_substr(line, 0, 2));
		if ((*line == '(') || (*line == ')'))
			return (ft_substr(line, 0, 1));
		if ((*line == '<' && *(line + 1) != '<') || (*line == '>' && *(line
					+ 1) != '>'))
			return (ft_substr(line, 0, 1));
		if ((*line == '<' && *(line + 1) == '<') || (*line == '>' && *(line
					+ 1) == '>'))
			return (ft_substr(line, 0, 2));
	}
	else
	{
		while (line[lenght] && (ft_strchr(special, line[lenght]) == NULL
				&& ispacce(line[lenght]) != 1))
		{
			lenght++;
		}
	}
	while (ispacce(*line) == 1)
		line++;
	return (ft_substr(line, 0, lenght));
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
