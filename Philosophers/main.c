/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:22:43 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/17 22:52:03 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
		*s1++ = (unsigned char)c;
	return (s);
}

int	main(int ac, char **av)
{
	t_general	g;

	if (ac != 5 && ac != 6)
	{
		printf("invalid number of argument\n");
		return (1);
	}
	creat_struct(&g, ac, av);
	if (parsing_general(&g) == 1)
	{
		free_struct(&g);
		printf("fail\n");
		return (1);
	}
	if (start_code(&g) == 1)
		return (free(g.ph), 1);
	if (g.compt == 1 && g.dead != 1)
		printf("all philo eat\n");
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
}
