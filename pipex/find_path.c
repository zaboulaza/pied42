/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:17:41 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/13 17:34:43 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path(char **av, char **env, t_general *g)
{
	int	i;

	i = 0;
	if (!env || !*env)
		return (1);
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			g->path_line = env[i];
		}
		i++;
	}
	test_av(av, g);
	return (0);
}

int	test_av(char **av, t_general *g)
{
	int	i;

	i = 0;
	(void)av;
	g->path_split = ft_split(g->path_line, ':');
	if (!g->path_split)
		return (1);
	put_back_slash(g);
	return (1);
}

int	put_back_slash(t_general *g)
{
	int		i;
	int		len;
	char	*tmp;

	len = 0;
	i = 0;
	rm_path(g);
	while (g->path_split[i])
	{
		len = ft_strlen(g->path_split[i]);
		tmp = malloc(len + 2);
		if (!tmp)
			return (1);
		ft_strlcpy(tmp, g->path_split[i], len + 1);
		tmp[len] = '/';
		tmp[len + 1] = '\0';
		free(g->path_split[i]);
		g->path_split[i] = tmp;
		i++;
	}
	return (0);
}

void	rm_path(t_general *g)
{
	int		size;
	char	*old;

	old = g->path_split[0];
	size = ft_strlen(g->path_split[0]);
	g->path_split[0] = ft_substr(g->path_split[0], 5, size - 5);
	free(old);
}
