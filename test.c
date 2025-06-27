/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:36:17 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/19 11:44:31 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count_len(char *nb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (nb[i])
	{
		while (((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32) && nb[i])
			i++;
		if ((!(nb[i] >= 9 && nb[i] <= 13) && !nb[i] == 32) && nb[i])
			count++;
		while ((!(nb[i] >= 9 && nb[i] <= 13) && nb[i] != 32) && nb[i])
			i++;
	}
	return (count);
}

char *malloc_word(char *str)
{
	int len = 0;
	int i = 0;
	char *str2;
	
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		str++;
	while ((!(str[len] >= 9 && str[len] <= 13) && str[len] != 32) && str[len])
		len++;
	str2 = malloc(len + 1);
	if (!str2)
		return (0);
	while (i < len)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}


char    **ft_split(char *str)
{
	char **tab;
	int leng = count_len(str);
	int i = 0;

	tab = malloc(sizeof(char *) * leng + 1);
	if (!tab)
		return (NULL);
	tab[leng] = NULL;
	while (*str)
	{
		while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
			str++;
		while ((!(*str >= 9 && *str <= 13) && *str != 32) && *str)
		{
			tab[i] = malloc_word(str);
			if (!tab[i])
				return (NULL);
			while ((!(*str >= 9 && *str <= 13) && *str != 32) && *str)
				str++;
		}
		i++;
	}
	return (tab);
}






int	main(void)
{
	char	**str;
	int i = 0;
	str = ft_split("bonjour tu vas bien ou pas ? ?");
	
	while (str[i])
	{
		printf("[%s]\n", str[i]);
		i++;
	}
}






// int	main(int ac, char **av)
// {
// 	int	nb;
// 	int	i;

// 	i = 2;
// 	if (ac == 2)
// 	{
// 		nb = atoi(av[1]);
// 		if (nb == 1)
// 		{
// 			printf("1\n");
// 			return (0);
// 		}
// 		while (i <= nb)
// 		{
// 			if (nb % i == 0)
// 			{
// 				printf("%d", i);
// 				if (nb != i)
// 				{
// 					printf("*");
// 				}
// 				nb = nb / i;
// 			}
// 			else
// 				i++;
// 		}
// 	}
// 	printf("\n");
// 	return (0);
// }
