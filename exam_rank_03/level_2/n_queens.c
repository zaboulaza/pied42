/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:07:16 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/20 20:49:51 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./n_queens.h"

int	is_safe(int *pos, int row, int col)
{
	int	prev_col;

	prev_col = 0;
	while (prev_col < col)
	{
		if (pos[prev_col] == row)
			return (0);
		if (abs(pos[prev_col] - row) == abs(prev_col - col))
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

void	solve(int *pos, int col, int n)
{
	int	row;

	if (col == n)
	{
		print_solution(pos, n);
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(pos, row, col))
		{
			pos[col] = row;
			solve(pos, col + 1, n);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*pos;

	if (ac != 2)
		return (0);
	n = atoi(av[1]);
	if (n == 0)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	pos = malloc(sizeof(int) * n);
	if (!pos)
		return (1);
	solve(pos, 0, n);
	free(pos);
	return (0);
}
