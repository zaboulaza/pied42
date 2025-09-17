/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_third_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:14:29 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/17 21:26:41 by nsmail           ###   ########.fr       */
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
		node = node->next->next;
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
	else if (node->type == OR)
		return (OR);
	else if (node->type == AND)
		return (AND);
	return (100);
}

// char	**next_command(t_node **original_node)
// {
// 	t_cmd *new_cmd = empty_command();
// 	char	**arg;
// 	t_node	*current_node = *original_node;

// 	while (/* current_node != SEPARATOR && current_node != NULL */)
// 	{
// 		if (/* current_node == WORD */)
// 		{
// 			if (/* new_cmd->type == SUBSHELL */)
// 				// return ERROR
// 			if (/* new_cmd->type == UNDEFINED */)
// 				// new_cmd->type = COMMAND

// 			// add_back(arg, node->content)
// 		}
// 		else if (/* current_node == SUBSHELL */)
// 		{
// 			if (/* new_cmd->type != UNDEFINED */)
// 				// return ERROR

// 			// new_cmd->type = SUBSHELL

// 			// arg[0] = PARENTHESIS CONTENT
// 		}
// 		else if (/* current_node == REDIRECTION */)
// 		{
// 			// t_files new_redir = new_redir()
// 			// add_back(new_cmd->files, new_redir)
// 		}
// 	}

// 	*original_node = current_node;

// 	if (/* new_cmd->type == UNDEFINED && new_cmd->files == NULL */)
// 		// return ERROR

// 	return (new_cmd);
// }

char	**find_arg(t_cmd *cmd, t_node *node, t_tmp **tmp)
{
	char	**arg;
	t_tmp	*cur;

	if (node->type >= REDIR_IN && node->type <= HEREDOC)
	{
		while (node && (node->type >= REDIR_IN && node->type <= HEREDOC))
		{
			add_to_tmp_liste(node, tmp);
			node = node->next->next;
			cur = *tmp;
		}
		if (!node || (node->type >= PIPE && node->type <= AND))
			find_arg_norm3(cmd, tmp, cur);
	}
	else if (cmd->type != CMD && cmd->type != SUBSHELL)
		return (NULL);
	else if (node->type == WORD)
	{
		arg = find_arg_norm(cmd, node, tmp);
		return (arg);
	}
	else if (cmd->type == SUBSHELL)
		return (find_arg_norm_parent(node, cmd, tmp));
	return (NULL);
}

char	**find_arg_norm_parent(t_node *node, t_cmd *cmd, t_tmp **tmp)
{
	char	**arg;
	int		count;

	count = find_arg_norm_parent2(node);
	arg = malloc(sizeof(char *) * 2);
	arg[0] = ft_strdup("");
	if (tmp)
	{
		add_tmp_to_list(cmd, tmp);
		clear_tmp(tmp);
		cmd->type = 11;
	}
	while (node && (count > 0))
	{
		arg[0] = ft_strjoin_(arg[0], node->content);
		node = node->next;
		count--;
	}
	arg[1] = NULL;
	while (node && (node->type >= REDIR_IN && node->type <= HEREDOC))
	{
		add_to_files_liste(cmd, node, tmp);
		node = node->next->next;
	}
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
