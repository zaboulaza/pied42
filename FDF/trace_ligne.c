/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ligne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:28:48 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/05 17:13:29 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

void	draw_line_between(t_general *g, t_point a, t_point b)
{
	g->b->zoom = 20;
	a.x *= g->b->zoom;
	a.y *= g->b->zoom;
	a.z *= g->b->zoom;
	b.x *= g->b->zoom;
	b.y *= g->b->zoom;
	b.z *= g->b->zoom;
	a.x += 1920 / 2;
	a.y += 1080 / 2;
	b.x += 1920 / 2;
	b.y += 1080 / 2;
	g->b->dx = a.x - g->tab[g->b->y][g->b->x].x;
	g->b->dy = g->tab[g->b->y + 1][g->b->x].y - g->tab[g->b->y][g->b->x].y;
	g->b->xx = g->tab[g->b->y][g->b->x].x;
	g->b->yy = g->tab[g->b->y][g->b->x].y;
	// printf("tu me vois 6 ?\n"); OK
	if (abs(g->b->dx) > abs(g->b->dy))
	{
		less_than_1(g);
		// printf("tu me vois 7 ?\n"); OK
	}
	else
	{
		more_than_1(g);
		printf("tu me vois 8 ?\n");
	}
}

void	less_than_1(t_general *g)
{
	g->b->y = 0;
	g->b->x = 0;
	g->b->i = 0;
	g->b->des = 2 * abs(g->b->dy) - abs(g->b->dx);
	printf("tu me vois 9 ?\n");
	my_mlx_pixel_put(g, g->b->xx, g->b->yy, g->tab[g->b->y][g->b->x].color);
	while (g->b->i < abs(g->b->dx))
	{
		printf("tu me vois 10 ?\n");
		if (g->b->dx > 0)
			g->b->xx += 1;
		else
			g->b->xx -= 1;
		if (g->b->des < 0)
		{
			g->b->des = g->b->des + 2 * abs(g->b->dy);
			printf("tu me vois 11 ?\n");
		}
		else
		{
			printf("tu me vois 12 ?\n");
			if (g->b->dy > 0)
				g->b->yy += 1;
			else
				g->b->yy -= 1;
			g->b->des = g->b->des + 2 * abs(g->b->dy) - 2 * abs(g->b->dx);
		}
		my_mlx_pixel_put(g, g->b->xx, g->b->yy, g->tab[g->b->y][g->b->x].color);
		g->b->i++;
		printf("tu me vois 13 ?\n");
	}
}

void	more_than_1(t_general *g)
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
		my_mlx_pixel_put(g, g->b->xx, g->b->yy, g->tab[g->b->y][g->b->x].color);
		g->b->i++;
	}
}

void	draw_map(t_general *g)
{
	int	x;
	int	y;

	y = 0;
	// printf("tu me vois 1 ?\n"); OK
	while (y < g->nb->length)
	{
		x = 0;
		while (x < g->nb->height)
		{
			// printf("tu me vois 2 ?\n"); OK
			draw_line(g, x, y);
			x++;
		}
		y++;
	}
}

void	draw_line(t_general *g, int x, int y)
{
	// printf("tu me vois 3 ?\n"); OK
	if (x + 1 < g->nb->length)
	{
		draw_line_between(g, g->tab[y][x], g->tab[y][x + 1]);
		// printf("tu me vois 4 ?\n"); OK
	}
	if (y + 1 < g->nb->height)
	{
		draw_line_between(g, g->tab[y][x], g->tab[y + 1][x]);
		// printf("tu me vois 5 ?\n"); OK
	}
}
