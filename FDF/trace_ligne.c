/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ligne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:48 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/16 19:51:40 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

void	draw_map(t_general *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->nb->height)
	{
		x = 0;
		while (x < g->nb->length - 1)
		{
			draw_line(g, x, y);
			x++;
		}
		y++;
	}
}

void	draw_line(t_general *g, int x, int y)
{
	if (x + 1 < g->nb->length - 1)
		draw_line_between(g, g->tab[y][x], g->tab[y][x + 1]);
	if (y + 1 < g->nb->height)
		draw_line_between(g, g->tab[y][x], g->tab[y + 1][x]);
}

void	draw_line_between(t_general *g, t_point a, t_point b)
{
	centre_zoom(g, &a, &b);
	rotate_x(&a, g->cam->alpha);
	rotate_y(&a, g->cam->beta);
	rotate_z(&a, g->cam->gamma);
	rotate_x(&b, g->cam->alpha);
	rotate_y(&b, g->cam->beta);
	rotate_z(&b, g->cam->gamma);
	isometrique_projection(&a, g);
	isometrique_projection(&b, g);
	a.x += WIN_LENGTH / 2 + g->cam->decal_x;
	a.y += WIN_HEIGHT / 2 + g->cam->decal_y;
	b.x += WIN_LENGTH / 2 + g->cam->decal_x;
	b.y += WIN_HEIGHT / 2 + g->cam->decal_y;
	g->b->dx = b.x - a.x;
	g->b->dy = b.y - a.y;
	g->b->xx = a.x;
	g->b->yy = a.y;
	if (abs(g->b->dx) > abs(g->b->dy))
		less_than_1(g, a, b);
	else
		more_than_1(g, a, b);
}

void	less_than_1(t_general *g, t_point a, t_point b)
{
	g->b->y = 0;
	g->b->x = 0;
	g->b->i = 0;
	g->b->des = 2 * abs(g->b->dy) - abs(g->b->dx);
	my_mlx_pixel_put(g, g->b->xx, g->b->yy, g->tab[g->b->y][g->b->x].color);
	while (g->b->i < abs(g->b->dx))
	{
		if (g->b->dx > 0)
			g->b->xx += 1;
		else
			g->b->xx -= 1;
		if (g->b->des < 0)
			g->b->des = g->b->des + 2 * abs(g->b->dy);
		else
		{
			if (g->b->dy > 0)
				g->b->yy += 1;
			else
				g->b->yy -= 1;
			g->b->des = g->b->des + 2 * abs(g->b->dy) - 2 * abs(g->b->dx);
		}
		g->b->color_gradent = get_color(g->b->xx, g->b->yy, &a, &b);
		my_mlx_pixel_put(g, g->b->xx, g->b->yy, g->b->color_gradent);
		g->b->i++;
	}
}

void	more_than_1(t_general *g, t_point a, t_point b)
{
	g->b->y = 0;
	g->b->x = 0;
	g->b->i = 0;
	g->b->des = 2 * abs(g->b->dx) - abs(g->b->dy);
	my_mlx_pixel_put(g, g->b->xx, g->b->yy, g->tab[g->b->y][g->b->x].color);
	while (g->b->i < abs(g->b->dy))
	{
		if (g->b->dy > 0)
			g->b->yy += 1;
		else
			g->b->yy -= 1;
		if (g->b->des < 0)
			g->b->des = g->b->des + 2 * abs(g->b->dx);
		else
		{
			if (g->b->dx > 0)
				g->b->xx += 1;
			else
				g->b->xx -= 1;
			g->b->des = g->b->des + 2 * abs(g->b->dx) - 2 * abs(g->b->dy);
		}
		g->b->color_gradent = get_color(g->b->xx, g->b->yy, &a, &b);
		my_mlx_pixel_put(g, g->b->xx, g->b->yy, g->b->color_gradent);
		g->b->i++;
	}
}
