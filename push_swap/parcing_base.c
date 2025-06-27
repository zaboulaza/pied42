/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 07:32:38 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/26 09:33:07 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parcing_1(t_general *g, char **av)
{
	if (join_line(g, av) == 1)
		return (1);
	if (verif_good_format(g) == 1)
		return (1);
	if (split_number(g) == 1)
		return (1);
	if (verif_same_nb(g->stacks->stack_a) == 1)
	{
		printf("err\n");
		return (1);
	}
	return (0);
}

int	join_line(t_general *g, char **av)
{
	t_parcing	*prcg;
	int			i;

	i = 1;
	prcg = g->prcg;
	if (prcg && prcg->arg_join == NULL)
		prcg->arg_join = ft_strdup("");
	if (!prcg->arg_join)
		return (1);
	while (av[i])
	{
		prcg->arg_join = ft_strjoin(prcg->arg_join, av[i]);
		i++;
	}
	return (0);
}

int	verif_good_cara(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 1 || s[i] == '+' || s[i] == '-' || s[i] == ' ')
		{
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	verif_good_format(t_general *g)
{
	int		i;
	char	*s;

	i = 0;
	s = g->prcg->arg_join;
	if (verif_good_cara(s) == 1)
		return (1);
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] && (s[i] == '+' || s[i] == '-'))
		{
			if (ft_isdigit(s[i + 1]))
				return (1);
			if (s[i - 1] != ' ' || s[i - 1] != 0)
				return (1);
			i++;
		}
		while (ft_isdigit(s[i]) == 1)
			i++;
	}
	return (0);
}

int	split_number(t_general *g)
{
	int	i;

	i = 0;
	g->prcg->nb_str = ft_split(g->prcg->arg_join, ' ');
	if (!g->prcg->nb_str)
		return (1);
	free(g->prcg->arg_join);
	while (g->prcg->nb_str[i] != NULL)
	{
		if (add_to_liste(&g->stacks->stack_a, g->prcg->nb_str[i]) == 1)
		{
			return (1);
		}
		i++;
	}
	free_tab(g->prcg->nb_str);
	return (0);
}
