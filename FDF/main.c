/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:26:35 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/24 06:53:15 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

int	main(int ac, char **av)
{
	t_nb_utile	nb;
	if (ac != 2)
		return (0);
	nb.fd = open(av[1], O_RDONLY);
	if (nb.fd == -1)
		return (0);
	if (parsing_general(&nb) == 0)
	{
		printf("fail\n");
		return (0);
	}
	printf("fin de boucle\n");
	close(nb.fd);
	return (0);
}
