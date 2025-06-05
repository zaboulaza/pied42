/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:26:35 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/05 14:57:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

int	main(int ac, char **av)
{
	t_general	g;

	creat_struct(&g);
	if (ac != 2)
		return (0);
	g.nb->fd = open(av[1], O_RDONLY);
	if (g.nb->fd == -1)
		return (0);
	if (parsing_general(&g, av[1]) == 0)
		return (0);
	close(g.nb->fd);
	test_mlx(&g);
	printf("fin de boucle\n");
	return (0);
}

void	creat_struct(t_general *g)
{
	g->nb = malloc(sizeof(t_nb_utile));
	g->pix = malloc(sizeof(t_pixel_put));
	g->mlx = malloc(sizeof(t_mlx));
	g->b = malloc(sizeof(t_general));
}
