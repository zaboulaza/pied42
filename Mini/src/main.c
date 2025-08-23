/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:24:27 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/23 18:45:51 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mini.h"

int	main(int ac, char **av, char **env)
{
	t_general	g;

	(void)env;
	creat_struct(&g, ac, av);
	while (1)
	{
		g.one_line = readline("mini> ");
		if (!g.one_line)
		{
			printf("exit\n");
			break ;
		}
		if (*g.one_line)
		{
			printf("Tu as écrit: %s\n", g.one_line);
			if (parsing_general(&g) == 1)
			{
				free_all(&g);
				return (1); // erreur
			}
			// print_list(&g.node);
		}
	}
	return (0);
}

void	creat_struct(t_general *g, int ac, char **av)
{
	ft_memset(g, 0, sizeof(t_general));
	g->ac = ac;
	g->av = av;
	g->node = ft_calloc(1, sizeof(t_node));
	if (!g->node)
		exit(1);
}

void	free_all(t_general *g)
{
	if (g->one_line)
		free(g->one_line);
}

void	print_list(t_node **node)
{
	t_node	*first;

	first = *node;
	while (first->next != NULL)
	{
		printf("id = %d\n", first->id);
		printf("type = %d\n", first->type);
		printf("content = %s\n", first->content);
		printf("\n\n");
		first = first->next;
	}
}
