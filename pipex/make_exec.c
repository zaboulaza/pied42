/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 05:07:14 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/18 17:39:24 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	start_exec(t_general *g, char **av, char **env, int i_av)
{
	int	i;

	i = 0;
	if (ft_strlen(av[i_av]) == 0)
		return (1);
	g->first_av = ft_split(av[i_av], ' ');
	while (g->path_split[i])
	{
		g->path_split[i] = ft_strjoin(g->path_split[i], g->first_av[0]);
		i++;
	}
	i = 0;
	while (g->path_split[i] != 0)
	{
		if (access(g->path_split[i], X_OK) == 0)
		{
			
			execve(g->path_split[i], g->first_av, env);
		}
		i++;
	}
	perror("execve");
	return (1);
}
