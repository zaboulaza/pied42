/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:42:26 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/23 05:15:04 by zaboulaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mini.h"

int  creat_list(t_general *g)
{
    if (add_to_liste(&g->node, (char *)g->one_line) == 1)
    {
        return (1);
    }
    return (0);
}

int add_to_liste(t_node **node ,char *line)
{
    t_node *new;
    t_node *tmp;
    
    while (*line)
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
        line = next_step(line);
    }
    return (0);
}
t_node *new_node(char *line)
{
    
}

char *next_step(char *line)
{
    char special[7] = "|&()<>";
    
    if (ft_strchr(special, *line) != NULL)
    {
        if ((*line == '|' && *(line + 1) == '|') || (*line == '&' && *(line + 1) == '&'))
            return (line + 2);
        if (*line == '|' && *(line + 1) != '|')
            return (line + 1);
        if ((*line == '(') || (*line == ')') || (*line == ')'))
            return (line + 1);
        if ((*line == '<' && *(line + 1) == '<') || (*line == '>' && *(line + 1) == '>'))
            return (line + 2);
        if ((*line == '<' && *(line + 1) != '<') || (*line == '>' && *(line + 1) != '>'))
            return (line + 1);
    }
    else
    {
        while (*line && ft_strchr(special, *line) == NULL)
            line++;
    }
    return (line);
}
