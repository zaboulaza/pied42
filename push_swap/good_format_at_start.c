/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_format_at_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:30:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/02 19:31:47 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_format_start(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	int		size;

	size = size_(stack_a);
	if (size <= 1)
		return (1);
	first_a = *stack_a;
	if (size == 2 && first_a->nb > first_a->next->nb)
		sa(stack_a);
	else if (size == 3)
	{
		sort_3(stack_a);
		return (0);
	}
	else if (size == 5)
	{
		sort_5(stack_a, stack_b);
		return (0);
	}
	first_a = *stack_a;
	if (all_is_good(first_a) == 0)
		return (0);
	return (1);
}

int	all_is_good(t_stack *first_a)
{
	while (first_a->next != NULL)
	{
		if (first_a->nb < first_a->next->nb)
			first_a = first_a->next;
		else
			return (1);
	}
	return (0);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	a = *stack_a;
	b = a->next;
	c = b->next;
	if (a->nb > b->nb && b->nb < c->nb && a->nb < c->nb)
		sa(stack_a);
	else if (a->nb > b->nb && b->nb > c->nb)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a->nb > b->nb && b->nb < c->nb && a->nb > c->nb)
		ra(stack_a);
	else if (a->nb < b->nb && b->nb > c->nb && a->nb < c->nb)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a->nb < b->nb && b->nb > c->nb && a->nb > c->nb)
		rra(stack_a);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		index;

	index = 1;
	tmp = *stack_a;
	index = sort_5_0(tmp, stack_a, index);
	sort_5_1(stack_a, stack_b, index);
	tmp = *stack_a;
	index = sort_5_0(tmp, stack_a, index);
	sort_5_2(stack_a, stack_b, index);
}
