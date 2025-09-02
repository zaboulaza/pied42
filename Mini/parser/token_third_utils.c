/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_third_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:14:29 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/02 02:03:16 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

t_node	*next_step_norm_cmd(t_node *node)
{
	int	count;

	count = 1;
	node = node->next;
	while (node && count > 0)
	{
		if (node->type == OPEN_PAREN)
			count++;
		else if (node->type == CLOSE_PAREN)
			count--;
		node = node->next;
	}
	while (node && (node->type >= REDIR_IN && node->type <= HEREDOC))
		node = node->next;
	return (node);
}

int	find_cmd_type(t_node *node)
{
	if (node->type == WORD)
		return (CMD);
	else if (node->type == OPEN_PAREN)
		return (SUBSHELL);
	else if (node->type == PIPE)
		return (PIPE);
	else if (node->type == DOUBLE_PIPE)
		return (DOUBLE_PIPE);
	else if (node->type == ESPERLUETTE)
		return (ESPERLUETTE);
	return (0);
}

char	**find_arg(t_cmd *cmd, t_node *node)
{
	char	*tmp;
	char	**arg;

	tmp = ft_strdup("");
	if (cmd->type != CMD && cmd->type != SUBSHELL)
		return (NULL);
	else if (node->type == WORD)
	{
		while (node != NULL && node->type == WORD)
		{
			tmp = ft_strjoin_(tmp, node->content);
			node = node->next;
			while (node != NULL && (node->type >= REDIR_IN
					&& node->type <= HEREDOC))
			{
				node = node->next;
				node = node->next;
			}
		}
		arg = ft_split_(tmp, ' ');
		if (!arg)
			return (NULL);
		return (arg);
	}
	// else if (node->type == OPEN_PAREN)
	// {
	// 	while (node != NULL && node->type != CLOSE_PAREN)
	// 	{
	// 		tmp = ft_strjoin(tmp, node->content);
	// 		node = node->next;
	// 	}
	// 	*arg = ft_strdup(tmp);
	// }
	return (arg);
}

char	*ft_strjoin_(char *s1, char const *s2)
{
	size_t	tailleg;
	int		i;
	size_t	j;
	char	*s3;

	if (!s1)
		return (NULL);
	tailleg = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	s3 = malloc(tailleg + 2);
	if (!s3)
		return (free(s1), NULL);
	while (s1[++i])
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = ' ';
	s3[i + 1] = '\0';
	free(s1);
	return (s3);
}
