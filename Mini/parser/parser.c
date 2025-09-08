/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:35:38 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/08 12:48:24 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	parsing_general(t_general *g, t_free *f)
{
	if (token_first(g) == 1)
	{
		free_all(g, f);
		return (1);
	}
	if (add_to_liste(&g->node, g->one_line, f) == 1)
	{
		free_all(g, f);
		return (1);
	}
	if (token_second(&g->node) == 1)
	{
		free_all(g, f);
		return (1);
	}
	if (token_third(g, f) == 1)
	{
		free_all(g, f);
		return (1);
	}
	return (0);
}
