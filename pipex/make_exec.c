/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 05:07:14 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/22 00:19:34 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	start_exec(t_general *g, int i_av)
{
	int	i;

	i = 0;
	if (ft_strlen(g->av[i_av]) == 0)
		return (1);
	g->first_av = ft_split(g->av[i_av], ' ');
	while (g->path_split[i])
	{
		g->path_split[i] = ft_strjoin(g->path_split[i], g->first_av[0]);
		i++;
	}
	i = 0;
	while (g->path_split[i] != 0)
	{
		if (access(g->path_split[i], X_OK) == 0)
			execve(g->path_split[i], g->first_av, g->env);
		i++;
	}
	perror("execve");
	return (1);
}
