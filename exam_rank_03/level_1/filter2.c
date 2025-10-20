/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:43:17 by zaboulaza         #+#    #+#             */
/*   Updated: 2025/10/16 12:19:02 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	finded(char *str, char *censur)
{
	int	i;

	i = 0;
	while (censur[i])
	{
		if (!str[i])
			return (0);
		if (censur[i] == str[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	filter(char *str, char *censur)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = strlen(censur);
	while (str[i])
	{
		j = 0;
		if (finded(&str[i], censur))
		{
			while (j < len)
			{
				write(1, "*", 1);
				i++;
				j++;
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
	int		readed;
	char	c;
	char	in[10000];
	int		i;

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
	if (readed == -1)
		return (perror("Error"), 0);
	filter(in, av[1]);
	return (1);
}
