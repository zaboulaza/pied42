/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:19:29 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/30 21:19:37 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fils_de_flut.h"

void	my_mlx_pixel_put(t_general *g, int x, int y, int color)
{
	char	*dst;

	dst = g->mlx->addr + (y * g->mlx->line_length + x * (g->mlx->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_general *g)
{
    printf("keycode : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	(void)g;
	return (0);
}

void	test_mlx(t_general *g)
{
	g->mlx->ptr_mlx = mlx_init();
	g->mlx->mlx_win = mlx_new_window(g->mlx->ptr_mlx, 1920, 1080, "titre");
	g->mlx->img = mlx_new_image(g->mlx->ptr_mlx, 1920, 1080);
	g->mlx->addr = mlx_get_data_addr(g->mlx->img, &g->mlx->bits_per_pixel,
			&g->mlx->line_length, &g->mlx->endian);
	display_point(g);
	mlx_put_image_to_window(g->mlx->ptr_mlx, g->mlx->mlx_win, g->mlx->img, 0,
		0);
	mlx_key_hook(g->mlx->mlx_win, key_hook, &g);
	mlx_loop(g->mlx->ptr_mlx);
	free(g->mlx->ptr_mlx);
}

void	display_point(t_general *g)
{
	g->pix->x_pix = 300;
	g->pix->y_pix = 250;
	g->nb->i = 0;
	g->nb->j = 0;
	while (g->nb->j < g->nb->height)
	{
		g->nb->i = 0;
		g->pix->y_pix += 50;
		g->pix->x_pix = 300;
		while (g->nb->i < g->nb->length)
		{
			my_mlx_pixel_put(g, g->pix->x_pix, g->pix->y_pix, 0x00FF0000);
			g->pix->x_pix += 75;
			g->nb->i++;
		}
		g->nb->j++;
	}
}
