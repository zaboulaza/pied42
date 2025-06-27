/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:50:10 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/27 19:51:53 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_g(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*tmp_b;

	first_a = *stack_a;
	while (first_a != NULL)
	{
		first_b = *stack_b;
		while (first_b != NULL)
		{
			target_a(first_a, first_b);
			first_b = first_b->next;
		}
		if (!first_a->target)
		{
			tmp_b = *stack_b;
			while (tmp_b != NULL)
			{
				target_b(first_a, tmp_b);
				tmp_b = tmp_b->next;
			}
		}
		first_a = first_a->next;
	}
}

void	target_a(t_stack *first_a, t_stack *first_b)
{
	if (first_a->nb > first_b->nb)
	{
		if (first_a->target == NULL || first_a->target->nb < first_b->nb)
			first_a->target = first_b;
	}
}

void	target_b(t_stack *first_a, t_stack *tmp_b)
{
	if (first_a->nb < tmp_b->nb)
	{
		if (first_a->target == NULL || first_a->target->nb < tmp_b->nb)
			first_a->target = tmp_b;
	}
}
