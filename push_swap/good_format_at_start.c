/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_format_at_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:30:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/02 03:26:32 by nsmail           ###   ########.fr       */
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
	if (size == 2)
	{
		if (first_a->nb > first_a->next->nb)
			sa(stack_a);
	}
	if (size == 3)
	{
		sort_3(stack_a);
		return (0);
	}
	if (size == 5)
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
	t_stack	*first;
	t_stack	*tmp;
	int		index;
	int		nb;
	int		i;

	index = 0;
	i = 1;
	first = *stack_a;
	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	nb = tmp->nb;
	while (tmp != NULL)
	{
		if (nb > tmp->nb)
		{
			nb = tmp->nb;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (index == 1)
		pb(stack_a, stack_b);
	else if (index == 2)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 3)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 4)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 5)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	i = 1;
	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	nb = tmp->nb;
	index = tmp->index;
	while (tmp != NULL)
	{
		if (nb > tmp->nb)
		{
			nb = tmp->nb;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (index == 1)
		pb(stack_a, stack_b);
	else if (index == 2)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
