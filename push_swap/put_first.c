/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:52:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/29 03:37:49 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// mettre les index en premiere pos
/// @brief
/// @param stack_a
/// @param stack_b
/// @param nb_coup
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

	

	
	while (rotate_b != 0)
	{
		first_a = first_a->next;
		rotate_b--;
	}
	
	rotate_b = first_a->target->index;
	neg_b = first_a->target->up_down;
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

	t_stack		*ah = *stack_a;

	


	
	
	rotate_b = ah->target->index;
	neg_b = ah->target->up_down;

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
