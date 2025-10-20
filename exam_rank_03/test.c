/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:50:46 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/20 21:52:03 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
//-----------------------------------------------------------//
//   FONCTION : generate()                                   //
//-----------------------------------------------------------//
// Génère récursivement toutes les permutations possibles
// de la chaîne passée en argument.
//
// Paramètres :
// - str : chaîne triée de caractères uniques
// - result : tableau temporaire pour construire chaque permutation
// - used : tableau d'indicateurs (0 = non utilisé, 1 = déjà utilisé)
// - len : longueur de la chaîne
// - depth : profondeur actuelle (indice dans la permutation)
//
// Quand depth == len → on a une permutation complète à afficher.
void	generate(char *str, char *result, int *used, int len, int depth)
{
	int	i;

	// Cas de base : on a construit une permutation complète
	if (len == depth)
	{
		write(1, result, len); // Affiche la permutation
		write(1, "\n", 1);     // Retour à la ligne
		return ;
	}

	// Parcourt chaque caractère pour construire la permutation
	i = 0;
	while (i < len)
	{
		if (!used[i]) // Si ce caractère n’a pas encore été utilisé
		{
			used[i] = 1;                // On le marque comme utilisé
			result[depth] = str[i];     // On l’ajoute dans le résultat
			generate(str, result, used, len, depth + 1); // Récursion
			used[i] = 0;                // On le libère (backtracking)
		}
		i++;
	}
}


//-----------------------------------------------------------//
//   FONCTION PRINCIPALE : main()                            //
//-----------------------------------------------------------//
// Utilisation : ./a.out <chaine_sans_doublons>
//
// Exemple :
//   ./a.out abc
//
// Sortie :
//   abc
//   acb
//   bac
//   bca
//   cab
//   cba
//-----------------------------------------------------------
int	main(int ac, char **argv)
{
	if (ac != 2)
		return (1); // Erreur : mauvais arguments

	int *used;
	char *result;

	int len = ft_strlen(argv[1]); // Longueur de la chaîne

	// Allocation dynamique :
	// - "used" : tableau d'entiers pour savoir si chaque caractère est pris
	// - "result" : tableau pour construire une permutation complète
	used = calloc(len, sizeof(int));
	result = malloc(sizeof(char) * len + 1);
	if (!used || !result)
		return (1);

	// Trie la chaîne pour que les permutations soient générées dans l’ordre
	ft_sort(argv[1]);

	// Lancement de la génération récursive
	generate(argv[1], result, used, len, 0);

	// Libération mémoire
	free(used);
	free(result);
	return (0);
}