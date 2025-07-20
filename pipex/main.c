/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 02:29:35 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/20 06:55:25 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_general	g;

	if (ac < 2)
		return (1);
	init_function(&g);
	if (find_path(ac, av, env, &g))
	{
		free_function(&g);
		return (1);
	}
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		start_algo_here_doc(&g, ac, av, env);
	else
		start_algo(&g, ac, av, env);
	free_function(&g);
	return (0);
}

void	init_function(t_general *g)
{
	ft_memset(g, 0, sizeof(t_general));
	g->i_av = 2;
}

void	free_function(t_general *g)
{
	int	i;

	i = 0;
	if (g->path_split)
		free_tab(g->path_split);
	if (g->first_av)
		free_tab(g->first_av);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
