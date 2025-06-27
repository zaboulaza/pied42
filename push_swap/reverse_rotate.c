/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:51:11 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/25 16:09:54 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;
	t_stack	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (1);
	first = *stack_a;
	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->next->next == NULL)
			before_last = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	last->next = first;
	before_last->next = NULL;
	*stack_a = last;
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;
	t_stack	*tmp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (1);
	first = *stack_b;
	tmp = *stack_b;
	while (tmp->next != NULL)
	{
		if (tmp->next->next == NULL)
			before_last = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	last->next = first;
	before_last->next = NULL;
	*stack_b = last;
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (rra(stack_a) == 1)
		return (1);
	if (rrb(stack_b) == 1)
		return (1);
	write(1, "rrr\n", 4);
	return (0);
}

