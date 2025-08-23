/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:42:26 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/23 23:10:40 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

// int	add_to_liste(t_node **node, char *line)
// {
// 	t_node	*new;
// 	t_node	*tmp;

// 	while (*line != '\0')
// 	{
// 		new = new_node(line);
// 		if (!new)
// 			return (1);
// 		if (!*node)
// 			*node = new;
// 		else
// 		{
// 			tmp = *node;
// 			while (tmp->next != NULL)
// 				tmp = tmp->next;
// 			tmp->next = new;
// 		}
// 		line = next_step(line);
// 	}
// 	list_size(*node);
// 	return (0);
// }

int add_to_liste(t_node **node, char *line)
{
    t_node *new;
    t_node *tmp;
    char *start = line;

    while (*line != '\0') {
        // Sauvegarde le début du token courant
        start = line;
        
        new = new_node(line);
        if (!new)
            return (1);
        
        if (!*node)
            *node = new;
        else {
            tmp = *node;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = new;
        }
        
        // Avance correctement selon le type de token
        line = next_step(line);
        
        // Vérification pour éviter les boucles infinies
        if (line == start) {
            printf("Erreur: avancement bloqué à: %s\n", line);
            break;
        }
    }
    list_size(*node);
    return (0);
}

t_node *new_node(char *line)
{
    t_node *node;
    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    
    node->type = find_type(line);
    node->content = find_content(line);
    node->next = NULL;
    
    // Debug
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
		if (*line == '|' && *(line + 1) != '|')
			return (line + 1);
		if (*line == '(' || *line == ')')
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
