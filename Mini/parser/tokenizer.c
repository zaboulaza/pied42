/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:04:26 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/23 04:22:48 by zaboulaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mini.h"

int	token(t_general *g)
{
	if (first_verif(g) == 1)
		return (1);
	return (0);
}

int	first_verif(t_general *g)
{
	if (bracket(g) == 1)
	{
		printf("parents not good\n");
		return (1);
	}
	if (quote(g) == 1)
	{
		printf("quote not good\n");
		return (1);
	}
	return (0);
}
