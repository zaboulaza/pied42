/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:43:17 by zaboulaza         #+#    #+#             */
/*   Updated: 2025/10/21 00:35:50 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	is_censor(char *str, char *censor)
{
	int	i;

	i = 0;
	while(censor[i])
	{
		if (!str[i])
			return (0);
		if (str[i] == censor[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	filter(char *str, char *censor)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = strlen(censor);
	while (str[i])
	{
		j = 0;
		if (is_censor(&str[i], censor))
		{
			while (j < len)
			{
				write(1, "*", 1);
				j++;
				i++;
			}
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	c;
	int		readed;
	char	in[100000];

	i = 0;
	if (ac != 2 || !av[1][0])
		return (0);
	readed = read(0, &c, 1);
	while (readed)
	{
		in[i] = c;
		readed = read(0, &c, 1);
		i++;
	}
	filter(in, av[1]);
	return (1);
}
