/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:54:49 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/22 21:54:09 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mini.h"

int	parents(t_general *g)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (g->one_line[i])
	{
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
