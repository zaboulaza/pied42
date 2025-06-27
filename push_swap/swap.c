/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 05:04:19 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/22 19:26:00 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (1);
	first = *stack_a;
	second = first->next;
	third = first->next->next;
	second->next = first;
	first->next = third;
	*stack_a = second;
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (1);
	first = *stack_b;
	second = first->next;
	third = first->next->next;
	second->next = first;
	first->next = third;
	*stack_b = second;
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (sa(stack_a) == 1)
		return (1);
	if (sb(stack_b) == 1)
		return (1);
	write(1, "ss\n", 3);
	return (0);
}
