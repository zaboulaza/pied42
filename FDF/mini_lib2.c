/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:27:36 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/16 19:54:53 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

void	zoom(int keycode, t_general *g)
{
	if (keycode == Z_PLUS)
		g->cam->z += 2;
	else if (keycode == Z_LESS)
		g->cam->z -= 2;
	else if (keycode == ZOOM_ASTERIX)
		g->cam->zoom *= 1.1;
	else if (keycode == DEZOOM_SLASH)
		g->cam->zoom *= 0.9;
}

void	move(int keycode, t_general *g)
{
	if (keycode == LEFT_ROTATION_SEVEN)
		g->cam->gamma += 0.1;
	else if (keycode == RIGHT_ROTATION_NINE)
		g->cam->gamma -= 0.1;
	else if (keycode == FIVE)
		g->cam->alpha -= 0.1;
	else if (keycode == EIGHT)
		g->cam->alpha += 0.1;
	else if (keycode == SIX)
		g->cam->beta += 0.1;
	else if (keycode == FOUR)
		g->cam->beta -= 0.1;
	else if (keycode == RIGHT_ARROW)
		g->cam->decal_x += 100;
	else if (keycode == LEFT_ARROW)
		g->cam->decal_x -= 100;
	else if (keycode == TOP_ARROW)
		g->cam->decal_y -= 100;
	else if (keycode == BOTTOM_ARROW)
		g->cam->decal_y += 100;
	else if (keycode == SPACE)
		reset(g);
}

void	reset(t_general *g)
{
	g->cam->gamma = 0;
	g->cam->alpha = 0;
	g->cam->beta = 0;
	g->cam->decal_y = 0;
	g->cam->decal_x = 0;
}

int	close_win(t_general *g)
{
	mlx_destroy_image(g->mlx->ptr_mlx, g->mlx->img);
	mlx_destroy_window(g->mlx->ptr_mlx, g->mlx->mlx_win);
	mlx_destroy_display(g->mlx->ptr_mlx);
	free(g->mlx->ptr_mlx);
	free_struct(g);
	exit(1);
}
