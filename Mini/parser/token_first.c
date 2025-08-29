/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:04:26 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/29 14:52:14 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	token_first(t_general *g)
{
	if (quote(g) == 1)
	{
		printf("quote not good\n");
		return (1);
	}
	if (bracket(g) == 1)
	{
		printf("parents not good\n");
		return (1);
	}
	if (esperluette(g) == 1)
	{
		printf("esperluette not good\n");
		return (1);
	}
	return (0);
}

int	bracket(t_general *g)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (g->one_line[i])
	{
		if (g->one_line[i] == '"')
		{
			i++;
			while (g->one_line[i] != '"')
				i++;
		}
		if (g->one_line[i] == ')')
			count--;
		else if (g->one_line[i] == '(')
			count++;
		if (count < 0)
			return (1);
		i++;
	}
	if (count != 0)
		return (1);
	return (0);
}

int	quote(t_general *g)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (g->one_line[i])
	{
		if (g->one_line[i] == '"')
			count++;
		i++;
	}
	if (count % 2 != 0)
		return (1);
	count = 0;
	i = 0;
	while (g->one_line[i])
	{
		if (g->one_line[i] == 39)
			count++;
		i++;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}

int	esperluette(t_general *g)
{
	int	i;

	i = 0;
	while (g->one_line[i])
	{
		if (g->one_line[i] == '&')
		{
			if (g->one_line[i] == '"')
			{
				i++;
				while (g->one_line[i] != '"')
					i++;
			}
			if (g->one_line[i + 1] != '&')
				return (1);
			else
				i++;
		}
		i++;
	}
	return (0);
}
