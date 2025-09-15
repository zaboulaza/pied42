/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:35:38 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/15 21:29:19 by zaboulaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	parsing_general(t_general *g, t_tmp **tmp)
{
	if (token_first(g) == 1)
		return (1);
	if (add_to_liste(&g->node, g->one_line) == 1)
		return (1);
	if (token_second(&g->node) == 1)
		return (1);
	if (token_third(g, tmp) == 1)
		return (1);
	if (last_verif_parent(g->cmd) == 1)
		return (1);
	return (0);
}
