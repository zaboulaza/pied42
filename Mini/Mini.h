/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:14:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/21 21:58:47 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft/libft.h"
# include "stdio.h"
# include <limits.h>

typedef struct s_general
{
	// main.c
	int		ac;
	char	**av;

	// parcing
	char	*one_big_line;
}			t_general;

// main.c
int			main(int ac, char **av);
void		creat_struct(t_general *g, int ac, char **av);

// parser.c
int			parsing_general(t_general *g);

// tokenizer.c
int			format(t_general *g);
int			one_big_line(t_general *g);

#endif