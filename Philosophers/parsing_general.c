/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_general.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 03:27:01 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/17 00:02:17 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	parsing_general(t_general *g)
{
	if (verif_good_cara(g) == 1)
		return (1);
	if (atoi_(g) == 1)
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nb)
{
	int	i;
	int	neg;
	int	res;

	res = 0;
	i = 0;
	neg = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			neg = 1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = (res * 10) + (nb[i] - '0');
		i++;
	}
	if (neg == 1)
		res = res * -1;
	return (res);
}

int	verif_good_cara(t_general *g)
{
	int	i;
	int	j;

	i = 1;
	while (i < g->ac)
	{
		j = 0;
		while (g->av[i][j])
		{
			if (ft_isalnum(g->av[i][j]) != 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	atoi_(t_general *g)
{
	int			i;
	int			j;
	long long	verif;
	int			tab[5];

	j = 0;
	verif = 0;
	i = 1;
	while (g->av[i])
	{
		verif = ft_atol(g->av[i]);
		if (verif > INT_MAX)
			return (1);
		tab[j] = ft_atoi(g->av[i]);
		i++;
		j++;
	}
	g->nb_philo = tab[0];
	g->t_die = tab[1];
	g->t_eat = tab[2];
	g->t_sleep = tab[3];
	if (g->ac == 6)
		g->eat_nb = tab[4];
	return (0);
}
