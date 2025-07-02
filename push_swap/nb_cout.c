/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_cout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:58:13 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/02 19:35:42 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_coup_g(t_stack **stack_a)
{
	t_stack	*first_a;
	t_stack	*tmp;
	int		nb;
	int		most_valuable;

	tmp = NULL;
	first_a = *stack_a;
	stock_count(first_a);
	first_a = *stack_a;
	nb = -1;
	while (first_a)
	{
		if (nb == -1 || first_a->count < nb)
		{
			nb = first_a->count;
			most_valuable = first_a->index;
			tmp = first_a;
		}
		first_a = first_a->next;
	}
	if (tmp && tmp->up_down == -1)
		most_valuable = most_valuable * -1;
	return (most_valuable);
}

void	stock_count(t_stack *first_a)
{
	t_stack	*tmp;

	tmp = first_a;
	while (tmp != NULL)
	{
		tmp->count = tmp->index + tmp->target->index;
		tmp = tmp->next;
	}
	tmp = first_a;
}
