/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:26:35 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/18 10:50:09 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

int	main(int ac, char **av)
{
	t_general	g;

	creat_struct(&g);
	if (ac != 2)
	{
		free_struct(&g);
		return (0);
	}
	g.nb->fd = open(av[1], O_RDONLY);
	if (g.nb->fd == -1)
	{
		free_struct(&g);
		return (EXIT_FAILURE);
	}
	if (parsing_general(&g, av[1]) == 0)
	{
		close(g.nb->fd);
		free_struct(&g);
		return (0);
	}
	close(g.nb->fd);
	test_mlx(&g);
	free_struct(&g);
	return (0);
}

void	creat_struct(t_general *g)
{
	ft_memset(g, 0, sizeof(t_general));
	g->nb = calloc(1, sizeof(t_nb_utile));
	if (!g->nb)
		exit(EXIT_FAILURE);
	g->pix = malloc(sizeof(t_pixel_put));
	if (!g->pix)
		exit(EXIT_FAILURE);
	g->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!g->mlx)
		exit(EXIT_FAILURE);
	g->b = ft_calloc(1, sizeof(t_bresenham));
	if (!g->b)
		exit(EXIT_FAILURE);
	g->cam = malloc(sizeof(t_camera));
	if (!g->cam)
		exit(EXIT_FAILURE);
	ft_memset(g->cam, 0, sizeof(t_camera));
	g->cam->zoom = 15;
	g->cam->decal_x = 0;
	g->cam->decal_y = 0;
	g->cam->z = 1;
}

void	free_struct(t_general *g)
{
	g->nb->i = 0;
	if (g->tab)
	{
		while (g->nb->i < g->nb->height)
			free(g->tab[g->nb->i++]);
		free(g->tab);
	}
	if (g->pix)
		free(g->pix);
	if (g->cam)
		free(g->cam);
	if (g->b)
		free(g->b);
	if (g->mlx)
		free(g->mlx);
	if (g->nb)
	{
		if (g->nb->ligne)
			free(g->nb->ligne);
		if (g->nb->map)
			free(g->nb);
	}
}
