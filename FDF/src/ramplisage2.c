/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramplisage2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:07:31 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/15 03:42:22 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fils_de_flut.h"

// void	verif(t_general *g, int z)
// {
// 	if (!g->z->max)
// 		g->z->max = g->z->min;
// 	if (z > g->z->max)
// 		g->z->max = z;
// 	if (z < g->z->min)
// 		g->z->min = z;
// }

void	init(t_general *g)
{
	// g = ft_memset(g, 0, sizeof(t_general));
	g->tab = ft_calloc(sizeof(t_point), (g->nb->length) * g->nb->height);
	g->nb->i = 0;
	while (g->nb->i < g->nb->height)
	{
		g->tab[g->nb->i] = malloc((g->nb->length + 1) * sizeof(t_point));
		// ft_memset(g->tab[g->nb->i], 0, sizeof(t_point));
		g->nb->i++;
	}
	// g->tab[g->nb->i] = 0;
}
