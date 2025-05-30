/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:19:41 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/30 21:12:16 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fils_de_flut.h"

// int	*parse_line(char **splitted_line, int len)
// {
// 	int	*tab;
// 	int	i;
// 	int	j;

// 	i = -1;
// 	j = -1;
// 	tab = (int *) malloc(sizeof(int) * ft_strlen(len));
// 	if (!tab)
// 		return (NULL);
// 	while (splitted_line[++i])
// 		tab[++j] = ft_atoi(splitted_line[i]);
// 	return (tab);
// }

int	parsing_general(t_general *g, char *argv1)
{
	if (argv1_good_format(g, argv1) == 0)
		return (0);
	if (one_big_line(g) == 0)
		return (0);
	if (count_word(g) == 0)
		return (0);
	g->nb->res_count_word = count_word(g);
	if (compare_height_ligne(g) == 0)
		return (0);
	return (1);
}

int	argv1_good_format(t_general *g, char *argv1)
{
	g->nb->i = 0;
	g->nb->len_argv1 = ft_strlen(argv1);
	if (argv1[g->nb->len_argv1 - 1] != 'f')
		return (0);
	if (argv1[g->nb->len_argv1 - 2] != 'd')
		return (0);
	if (argv1[g->nb->len_argv1 - 3] != 'f')
		return (0);
	if (argv1[g->nb->len_argv1 - 4] != '.')
		return (0);
	if (argv1[g->nb->len_argv1 - 5] == '/')
		return (0);
	return (1);
}

int	one_big_line(t_general *g)
{
	g->nb->height = 0;
	g->nb->i = 0;
	g->nb->ligne = NULL;
	if (g->nb->ligne == NULL)
		g->nb->ligne = ft_strdup("");
	if (g->nb->ligne == NULL)
		return (0);
	g->nb->temp_gnl = get_next_line(g->nb->fd);
	while (g->nb->temp_gnl)
	{
		g->nb->ligne = ft_strjoin(g->nb->ligne, g->nb->temp_gnl);
		if (g->nb->ligne == NULL)
		{
			free(g->nb->ligne);
			free(g->nb->temp_gnl);
			return (0);
		}
		g->nb->height++;
		g->nb->temp_gnl = get_next_line(g->nb->fd);
	}
	printf("ligne :\n%s\n\n", g->nb->ligne);
	printf("height : %d\n\n", g->nb->height);
	g->nb->map = ft_split(g->nb->ligne, '\n');
	while (g->nb->map[g->nb->i])
	{
		printf("map %d : %s\n", g->nb->i, g->nb->map[g->nb->i]);
		g->nb->i++;
	}
	printf("\n");
	return (1);
}

int	count_word(t_general *g)
{
	g->nb->length = 0;
	g->nb->i = 0;
	if (g->nb->ligne[g->nb->i] && g->nb->ligne[g->nb->i] == '\n')
		g->nb->i++;
	while (g->nb->ligne[g->nb->i] == ' ')
		g->nb->i++;
	while (g->nb->ligne[g->nb->i] != '\n' && g->nb->ligne[g->nb->i] != '\0')
	{
		g->nb->length++;
		while (g->nb->ligne[g->nb->i] != ' ' && g->nb->ligne[g->nb->i] != '\0'
			&& g->nb->ligne[g->nb->i] != '\n')
			g->nb->i++;
		while (g->nb->ligne[g->nb->i] == ' ')
			g->nb->i++;
	}
	printf("length : %d\n", g->nb->length);
	return (g->nb->length);
}

int	compare_height_ligne(t_general *g)
{
	g->nb->j = 0;
	while (g->nb->map[g->nb->j])
	{
		g->nb->i = 0;
		g->nb->length = 0;
		while (g->nb->map[g->nb->j][g->nb->i] == ' ')
			g->nb->i++;
		while (g->nb->map[g->nb->j][g->nb->i] != '\n'
			&& g->nb->map[g->nb->j][g->nb->i] != '\0')
		{
			g->nb->length++;
			while (g->nb->map[g->nb->j][g->nb->i] != ' '
				&& g->nb->map[g->nb->j][g->nb->i] != '\n'
				&& g->nb->map[g->nb->j][g->nb->i] != '\0')
				g->nb->i++;
			while (g->nb->map[g->nb->j][g->nb->i] == ' ')
				g->nb->i++;
		}
		if (g->nb->length != g->nb->res_count_word)
			return (0);
		g->nb->j++;
	}
	return (1);
}
