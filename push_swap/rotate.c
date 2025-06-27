/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:44:50 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/23 15:07:43 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (1);
	first = *stack_a;
	second = first->next;
	*stack_a = second;
	while (second->next != NULL)
		second = second->next;
	second->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (1);
	first = *stack_b;
	second = first->next;
	*stack_b = second;
	while (second->next != NULL)
		second = second->next;
	second->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ra(stack_a) == 1)
		return (1);
	if (rb(stack_b) == 1)
		return (1);
	write(1, "rr\n", 3);
	return (0);
}
