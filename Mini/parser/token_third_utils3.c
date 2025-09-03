/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_third_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:48:31 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/03 19:32:43 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	add_to_files_liste(t_cmd *cmd, t_node *node)
{
	t_files	*new;
	t_files	*tmp;

	new = new_files(node);
	if (!new)
		return (1);
	if (cmd->files == NULL)
	{
		printf("ls sdfdsfsdfsdf \n");
		cmd->files = new;
	}
	else
	{
		tmp = cmd->files;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

t_files	*new_files(t_node *node)
{
	t_files *file;

	file = malloc(sizeof(t_files));
	if (!file)
		return (NULL);
	ft_bzero(file, sizeof(t_files));
	file->mode = node->type;
	file->path = ft_strdup(node->next->content);
	file->next = NULL;
	return (file);
}


// int	add_to_files_liste(t_cmd *cmd, t_node *node)
// {
//     t_files	*new;
//     t_files	*tmp;

//     new = new_files(node);
//     if (!new)
//         return (1);
//     if (cmd->files == NULL)
//     {
//         cmd->files = new;
//     }
//     else
//     {
//         tmp = cmd->files;
//         while (tmp->next != NULL)
//             tmp = tmp->next;
//         tmp->next = new;
//     }
//     return (0);
// }

// t_files	*new_files(t_node *node)
// {
//     t_files *file = malloc(sizeof(t_files));
//     if (!file)
//         return (NULL);
//     ft_bzero(file, sizeof(t_files));
//     file->mode = node->type;
//     if (node->next)
//         file->path = ft_strdup(node->next->content);
//     else
//         file->path = NULL;
//     file->next = NULL;
//     return (file);
// }
