/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:35:38 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/09 16:50:05 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	parsing_general(t_general *g, t_tmp **tmp, t_free *f)
{
	if (token_first(g) == 1)
	{
		free_all(g, tmp, f);
		return (1);
	}
	if (add_to_liste(&g->node, g->one_line, g->free) == 1)
	{
		free_all(g, tmp, f);
		return (1);
	}
	if (token_second(&g->node) == 1)
	{
		free_all(g, tmp, f);
		return (1);
	}
	if (token_third(g, tmp) == 1)
	{
		free_all(g, tmp, f);
		return (1);
	}
	return (0);
}
