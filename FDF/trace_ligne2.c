/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ligne2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:36:56 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/15 02:30:14 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

void	isometrique_projection(t_point *p)
{
	int	tmp;

	tmp = p->x;
	p->x = (tmp - p->y) * cos(0.523599);
	p->y = (tmp + p->y) * sin(0.523599) - p->z;
}

float	fraction(int x, int y, t_point *a, t_point *b)
{
	int		dx;
	int		dy;
	float	fraction;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (abs(dx) > abs(dy))
	{
		if (b->x != a->x)
			fraction = (float)(x - a->x) / (float)(b->x - a->x);
		else
			return (0);
	}
	else
	{
		if (b->y != a->y)
			fraction = (float)(y - a->y) / (float)(b->y - a->y);
		else
			return (0);
	}
	return (fraction);
}

int	get_color(int x, int y, t_point *a, t_point *b)
{
	float	f;
	int		r;
	int		g;
	int		b_;

	f = fraction(x, y, a, b);
	r = a->r + f * (b->r - a->r);
	g = a->g + f * (b->g - a->g);
	b_ = a->b + f * (b->b - a->b);
	return ((r << 16) | (g << 8) | b_);
}

void	centre_zoom(t_general *g, t_point *a, t_point *b)
{
	a->x -= g->nb->length / 2;
	a->y -= g->nb->height / 2;
	b->x -= g->nb->length / 2;
	b->y -= g->nb->height / 2;
	a->x *= g->cam->zoom;
	a->y *= g->cam->zoom;
	a->z *= g->cam->zoom;
	b->x *= g->cam->zoom;
	b->y *= g->cam->zoom;
	b->z *= g->cam->zoom;
}
