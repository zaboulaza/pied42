/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:43:02 by zaboulaza         #+#    #+#             */
/*   Updated: 2025/10/13 01:45:10 by zaboulaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strcmp(char *str, char *censore)
{
	int	i;

	i = 0;
	while (censore[i])
	{
		if (!str[i])
			return (0);
		if (censore[i] == str[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	filter(char *str, char *censore)
{
	int	i;
	int	j;
	int	len;

	len = strlen(censore);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(&str[i], censore))
		{
			j = 0;
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
	char	c;
	char	in[10000];
	int		readed;
	int		i;

	i = 0;
	if (ac != 2 || !av[1][0])
		return (1);
	readed = read(0, &c, 1);
	if (readed == 0)
		return (perror("Error"), 0);
	while (readed)
	{
		in[i] = c;
		readed = read(0, &c, 1);
		i++;
	}
	in[i] = '\0';
	filter(in, av[1]);
	return (0);
}
