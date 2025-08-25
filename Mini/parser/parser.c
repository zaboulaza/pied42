/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:35:38 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/25 17:36:06 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	parsing_general(t_general *g)
{
	if (token_first(g) == 1)
		return (1);
	if (add_to_liste(&g->node, g->one_line) == 1)
		return (1);
	return (0);
}
