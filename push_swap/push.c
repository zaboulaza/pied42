/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:32:03 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/29 06:09:56 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_b;
	t_stack	*second_b;
	t_stack	*first_a;
	t_stack	*second_a;

	if (!stack_b || !*stack_b)
		return (0);
	first_b = *stack_b;
	second_b = first_b->next;
	if (!*stack_a)
	{
		*stack_a = first_b;
		first_b->next = NULL;
		*stack_b = second_b;
		write(1, "pa\n", 3);
		return (0);
	}
	first_a = *stack_a;
	second_a = first_a->next;
	first_b->next = first_a;
	*stack_b = second_b;
	*stack_a = first_b;
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*first_b;
	t_stack	*second_b;

	first_a = *stack_a;
	second_a = first_a->next;
	if (!*stack_b)
	{
		*stack_b = first_a;
		first_a->next = NULL;
		*stack_a = second_a;
		write(1, "pb\n", 3);
		return (0);
	}
	first_b = *stack_b;
	second_b = first_b->next;
	first_a->next = first_b;
	*stack_a = second_a;
	*stack_b = first_a;
	write(1, "pb\n", 3);
	return (0);
}
