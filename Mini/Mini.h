/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:14:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/22 21:38:49 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft/libft.h"
# include <limits.h>
# include <readline/readline.h>
# include <stdio.h>

typedef struct s_general
{
	// main.c
	int				ac;
	char			**av;

	// parcing
	char			*one_line;
	struct s_node	*node;
}					t_general;

// typedef struct s_node
// {
// 	int				type;
// 	char			*content;
// 	struct s_node	next;
// }					t_node;

// main.c
//////////////////////////////////////////////////////////////////////////////////////////
int					main(int ac, char **av, char **env);
void				creat_struct(t_general *g, int ac, char **av);
void				free_all(t_general *g);

// parser.c
////////////////////////////////////////////////////////////////////////////////////////
int					parsing_general(t_general *g);

// tokenizer.c
/////////////////////////////////////////////////////////////////////////////////////
int					token(t_general *g);

// c'est pour voir si y a pas de parentese ouverte ou guillemet seul
int					first_verif(t_general *g);
int					parents(t_general *g);
int					quote(t_general *g);

#endif