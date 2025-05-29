/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:19:41 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/29 20:12:45 by nsmail           ###   ########.fr       */
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

int	parsing_general(t_nb_utile *nb, char *argv1)
{
	if (argv1_good_format(nb, argv1) == 0)
		return (0);
	if (one_big_line(nb) == 0)
		return (0);
	if (count_word(nb) == 0)
		return (0);
	nb->res_count_word = count_word(nb);
	if (compare_height_ligne(nb) == 0)
		return (0);
	return (1);
}

int	argv1_good_format(t_nb_utile *nb, char *argv1)
{
	nb->i = 0;
	nb->len_argv1 = ft_strlen(argv1);
	if (argv1[nb->len_argv1 - 1] != 'f')
		return (0);
	if (argv1[nb->len_argv1 - 2] != 'd')
		return (0);
	if (argv1[nb->len_argv1 - 3] != 'f')
		return (0);
	if (argv1[nb->len_argv1 - 4] != '.')
		return (0);
	if (argv1[nb->len_argv1 - 5] == '/')
		return (0);
	return (1);
}

int	one_big_line(t_nb_utile *nb)
{
	nb->height = 0;
	nb->i = 0;
	nb->ligne = NULL;
	if (nb->ligne == NULL)
		nb->ligne = ft_strdup("");
	if (nb->ligne == NULL)
		return (0);
	nb->temp_gnl = get_next_line(nb->fd);
	while (nb->temp_gnl)
	{
		nb->ligne = ft_strjoin(nb->ligne, nb->temp_gnl);
		if (nb->ligne == NULL)
		{
			free(nb->ligne);
			free(nb->temp_gnl);
			return (0);
		}
		nb->height++;
		nb->temp_gnl = get_next_line(nb->fd);
	}
	printf("ligne :\n%s\n\n", nb->ligne);
	printf("height : %d\n\n", nb->height);
	nb->map = ft_split(nb->ligne, '\n');
	while (nb->map[nb->i])
	{
		printf("map %d : %s\n", nb->i, nb->map[nb->i]);
		nb->i++;
	}
	printf("\n");
	return (1);
}

int	count_word(t_nb_utile *nb)
{
	nb->length = 0;
	nb->i = 0;
	if (nb->ligne[nb->i] && nb->ligne[nb->i] == '\n')
		nb->i++;
	while (nb->ligne[nb->i] == ' ')
		nb->i++;
	while (nb->ligne[nb->i] != '\n' && nb->ligne[nb->i] != '\0')
	{
		nb->length++;
		while (nb->ligne[nb->i] != ' ' && nb->ligne[nb->i] != '\0'
			&& nb->ligne[nb->i] != '\n')
			nb->i++;
		while (nb->ligne[nb->i] == ' ')
			nb->i++;
	}
	printf("length : %d\n", nb->length);
	return (nb->length);
}

int	compare_height_ligne(t_nb_utile *nb)
{
	nb->j = 0;
	while (nb->map[nb->j])
	{
		nb->i = 0;
		nb->length = 0;
		while (nb->map[nb->j][nb->i] == ' ')
			nb->i++;
		while (nb->map[nb->j][nb->i] != '\n' && nb->map[nb->j][nb->i] != '\0')
		{
			nb->length++;
			while (nb->map[nb->j][nb->i] != ' ' && nb->map[nb->j][nb->i] != '\n'
				&& nb->map[nb->j][nb->i] != '\0')
				nb->i++;
			while (nb->map[nb->j][nb->i] == ' ')
				nb->i++;
		}
		if (nb->length != nb->res_count_word)
			return (0);
		nb->j++;
	}
	return (1);
}
