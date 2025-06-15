/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:27:36 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/15 18:36:57 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

void	zoom(int keycode, t_general *g)
{
	if (keycode == ZOOM_PLUS)
		g->cam->zoom *= 1.1;
	else if (keycode == DEZOOM_LESS)
		g->cam->zoom *= 0.9;
	else if (keycode == ZOOM_ASTERIX)
		g->cam->zoom *= 1.5;
	else if (keycode == DEZOOM_SLASH)
		g->cam->zoom *= 0.5;
}

void	move(int keycode, t_general *g)
{
	if (keycode == TOP_ARROW)
		g->cam->alpha += 0.1;
	else if (keycode == EIGHT)
		g->cam->alpha += 0.3;
	else if (keycode == BOTTOM_ARROW)
		g->cam->alpha -= 0.1;
	else if (keycode == TWO)
		g->cam->alpha -= 0.3;
	else if (keycode == RIGHT_ARROW)
		g->cam->beta += 0.1;
	else if (keycode == SIX)
		g->cam->beta += 0.3;
	else if (keycode == LEFT_ARROW)
		g->cam->beta -= 0.1;
	else if (keycode == FOUR)
		g->cam->beta -= 0.3;
	else if (keycode == LEFT_ROTATION_SEVEN)
		g->cam->gamma += 0.2;
	else if (keycode == RIGHT_ROTATION_NINE)
		g->cam->gamma -= 0.01;
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