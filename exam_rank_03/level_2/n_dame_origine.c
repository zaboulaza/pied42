/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_dame_origine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:21:33 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/20 20:44:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./n_queens_origine.h"

// Vérifie si une reine peut être placée à (row, col)
int	is_safe(int *pos, int row, int col)
{
	int prev_col = 0;

	while (prev_col < col)
	{
		if (pos[prev_col] == row) // même ligne
			return 0;
		if (abs(pos[prev_col] - row) == abs(prev_col - col)) // même diagonale
			return 0;
		prev_col++;
	}
	return 1;
}

// Affiche une solution complète : "p0 p1 ... pn-1"
void	print_solution(int *pos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i > 0) // espace seulement entre les nombres
			printf(" ");
		printf("%d", pos[i]); // ligne de la reine en colonne i
		i++;
	}
	printf("\n"); // fin de la ligne
}

// Algorithme de backtracking
void	solve(int *pos, int col, int n)
{
	int	row;

	if (col == n) // toutes les colonnes traitées → solution trouvée
	{
		print_solution(pos, n);
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(pos, row, col)) // si placement valide
		{
			pos[col] = row;        // place la reine
			solve(pos, col + 1, n); // passe à la colonne suivante
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	*pos;

	if (ac != 2) // doit avoir exactement 1 argument
		return (0);
	n = atoi(av[1]); // convertir argument en entier
	if (n == 0) // si 0 ou argument invalide → rien
		return (0);
	if (n == 2 || n == 3) // cas sans solutions
		return (1);
	pos = malloc(sizeof(int) * n); // tableau positions des reines
	if (!pos) // allocation échouée
		return (1);
	solve(pos, 0, n); // commence depuis la 1ère colonne
	free(pos); // libère mémoire
	return (0);
}
