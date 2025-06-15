/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:19:29 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/15 18:17:09 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

void	my_mlx_pixel_put(t_general *g, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIN_LENGTH || y > WIN_HEIGHT)
		return ;
	dst = g->mlx->addr + (y * g->mlx->line_length + x * (g->mlx->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_general *g)
{
	printf("keycode : %d\n", keycode);
	if (keycode == ESCAPE)
		close_win(g);
	move(keycode, g);
	zoom(keycode, g);
	return (0);
}

int	render(t_general *g)
{
	ft_bzero(g->mlx->addr, WIN_LENGTH * WIN_HEIGHT * 4);
	draw_map(g);
	mlx_put_image_to_window(g->mlx->ptr_mlx, g->mlx->mlx_win, g->mlx->img, 0,
		0);
	return (0);
}

void	mlx_first_verif(t_general *g)
{
	g->mlx->ptr_mlx = mlx_init();
	if (g->mlx->ptr_mlx == NULL)
		exit(EXIT_FAILURE);
	g->mlx->mlx_win = mlx_new_window(g->mlx->ptr_mlx, WIN_LENGTH, WIN_HEIGHT,
			"titre");
	if (g->mlx->mlx_win == NULL)
	{
		mlx_destroy_window(g->mlx->ptr_mlx, g->mlx->mlx_win);
		mlx_destroy_display(g->mlx->ptr_mlx);
		free(g->mlx->ptr_mlx);
		exit(EXIT_FAILURE);
	}
	g->mlx->img = mlx_new_image(g->mlx->ptr_mlx, WIN_LENGTH, WIN_HEIGHT);
	if (g->mlx->img == NULL)
	{
		mlx_destroy_window(g->mlx->ptr_mlx, g->mlx->mlx_win);
		mlx_destroy_display(g->mlx->ptr_mlx);
		free(g->mlx->ptr_mlx);
		exit(EXIT_FAILURE);
	}
	g->mlx->addr = mlx_get_data_addr(g->mlx->img, &g->mlx->bits_per_pixel,
			&g->mlx->line_length, &g->mlx->endian);
	if (g->mlx->addr == NULL)
	{
		mlx_destroy_window(g->mlx->ptr_mlx, g->mlx->mlx_win);
		mlx_destroy_display(g->mlx->ptr_mlx);
		free(g->mlx->ptr_mlx);
		exit(EXIT_FAILURE);
	}
}

void	test_mlx(t_general *g)
{
	mlx_first_verif(g);
	mlx_hook(g->mlx->mlx_win, 2, 1, key_hook, g);
	mlx_loop_hook(g->mlx->ptr_mlx, render, g);
	mlx_loop(g->mlx->ptr_mlx);
}
