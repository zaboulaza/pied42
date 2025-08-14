/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:22:43 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/14 17:07:36 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int ac, char **av)
{
	t_general	g;

	if (ac != 5 && ac != 6)
	{
		ft_printf("invalid number of argument\n");
		return (1);
	}
	creat_struct(&g, ac, av);
	if (parsing_general(&g) == 1)
	{
		free_struct(&g);
		ft_printf("fail\n");
		return (1);
	}
	start_code(&g);
	if (g.compt == 1)
		ft_printf("all philo eat\n");
	free_struct(&g);
	return (0);
}

void	creat_struct(t_general *g, int ac, char **av)
{
	ft_memset(g, 0, sizeof(t_general));
	g->ac = ac;
	g->av = av;
}

void	free_struct(t_general *g)
{
	if (g->ph)
		free(g->ph);
	if (g)
		free(g);
}

// void	print_list(t_general *g)
// {
// 	int	i;

// 	i = 0;
// 	while (i < g->ac - 1)
// 	{
// 		printf("av[%d] = %d\n", i, g->av_int[i]);
// 		i++;
// 	}
// }

// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	if (tab)
// 	{
// 		while (tab[i])
// 		{
// 			free(tab[i]);
// 			i++;
// 		}
// 		free(tab);
// 	}
// }
