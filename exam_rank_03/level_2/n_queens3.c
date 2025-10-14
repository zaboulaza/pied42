/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:47:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/14 21:10:34 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./n_queens.h"

int	is_solv(int *pos, int col, int row)
{
	int	prev_col;

	prev_col = 0;
	while (prev_col < col)
	{
		if (pos[prev_col] == row)
			return (0);
		if(abs(pos[prev_col] - row) == abs(prev_col - col))
			return (0);
		prev_col++;
	}
	return (1);
}

void	print_solution(int *pos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i > 0)
			printf(" ");
		printf("%d", pos[i]);
		i++;
	}
	printf("\n");
}

void	solv(int *pos, int col, int n)
{
	int	row;

	row = 0;
	if (col == n)
	{
		print_solution(pos, n);
		return ;
	}
	while (row < n)
	{
		if (is_solv(pos, col, row))
		{
			pos[col] = row;
			solv(pos, col + 1, n);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*pos;

	pos = 0;
	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	pos = malloc(sizeof(int) * n);
	if (!pos)
		return (1);
	if (n == 0)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	solv(pos, 0, n);
	free(pos);
	return (1);
}
