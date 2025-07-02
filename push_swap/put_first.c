/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:52:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/01 20:01:50 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_first(t_stack **stack_a, t_stack **stack_b, int index_to_move_a)
{
	t_stack	*first_a;
	t_stack	*first_b;
	int		rotate_b;
	int		neg_b;
	int		neg;

	neg = 1;
	first_a = *stack_a;
	first_b = *stack_b;
	if (index_to_move_a < 0)
	{
		neg = -1;
		index_to_move_a *= -1;
	}
	rotate_b = index_to_move_a;
	while (rotate_b-- != 0)
		first_a = first_a->next;
	rotate_b = first_a->target->index;
	neg_b = first_a->target->up_down;
	rotate_a(neg, index_to_move_a, stack_a);
	first_a = *stack_a;
	rotate_b = first_a->target->index;
	neg_b = first_a->target->up_down;
	rotate_bb(neg_b, rotate_b, stack_b);
}

void	rotate_a(int neg, int index_to_move_a, t_stack **stack_a)
{
	if (neg == -1)
	{
		while (index_to_move_a != 0)
		{
			rra(stack_a);
			index_to_move_a--;
		}
	}
	else
	{
		while (index_to_move_a != 0)
		{
			ra(stack_a);
			index_to_move_a--;
		}
	}
}

void	rotate_bb(int neg_b, int rotate_b, t_stack **stack_b)
{
	if (neg_b == -1)
	{
		while (rotate_b != 0)
		{
			rrb(stack_b);
			rotate_b--;
		}
	}
	else
	{
		while (rotate_b != 0)
		{
			rb(stack_b);
			rotate_b--;
		}
	}
}
