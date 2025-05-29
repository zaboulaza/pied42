/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:26:35 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/29 21:43:36 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

int	main(int ac, char **av)
{
	t_nb_utile	nb;
	t_mlx		mlx;
	t_pixel_put	pixel;

	if (ac != 2)
		return (0);
	nb.fd = open(av[1], O_RDONLY);
	if (nb.fd == -1)
		return (0);
	if (parsing_general(&nb, av[1]) == 0)
	{
		printf("fail\n");
		return (0);
	}
	close(nb.fd);
	mlx.nb = &nb;
	mlx.pixel = &pixel;
	test_mlx(&mlx);
	printf("fin de boucle\n");
	return (0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	printf("keycode : %d", keycode);
	if (keycode == 65307)
		exit(0);
	(void)mlx;
	printf("hello from key_hook!\n");
	return (0);
}

void	test_mlx(t_mlx *mlx)
{
	mlx->ptr_mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->ptr_mlx, 1920, 1080, "titre");
	mlx->img = mlx_new_image(mlx->ptr_mlx, 1920, 1080);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	display_point(mlx);
	my_mlx_pixel_put(mlx, 300, 300, 0x00FF0000);
	mlx_put_image_to_window(mlx->ptr_mlx, mlx->mlx_win, mlx->img, 0, 0);
	mlx_key_hook(mlx->mlx_win, key_hook, &mlx);
	mlx_loop(mlx->ptr_mlx);
	free(mlx->ptr_mlx);
}

void	display_point(t_mlx *mlx)
{
	mlx->pixel->x_pix = 300;
	mlx->pixel->y_pix = 250;
	mlx->nb->i = 0;
	mlx->nb->j = 0;
	// printf("height : %d\n", mlx->nb->height);
	while (mlx->nb->j < mlx->nb->height)
	{
		mlx->nb->i = 0;
		mlx->pixel->y_pix += 50;
		mlx->pixel->x_pix = 300;
		while (mlx->nb->i < mlx->nb->length)
		{
			my_mlx_pixel_put(mlx, mlx->pixel->x_pix, mlx->pixel->y_pix,
				0x00FF0000);
			mlx->pixel->x_pix += 75;
			mlx->nb->i++;
		}
		mlx->nb->j++;
	}
}

// int		i = 0;
// while (i < height)
// {
// 	char	**tokens;
// 	int		j;

// 	tokens = ft_split(map[i], ' ');
// 	j = 0;
// 	while (tokens[j])
// 	{
// 		tab[i][j].x = j;
// 		tab[i][j].y = i;
// 		tab[i][j].z = ft_atoi(tokens[j]); // juste la hauteur,
// 			à améliorer si couleur
// 		tab[i][j].color = 0xFFFFFF;       // défaut blanc (à parser si besoin)
// 		j++;
// 	}
// 	free_split(tokens); // pense à free après usage
// 	i++;
// }
