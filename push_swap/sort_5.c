/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:20:42 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/02 19:36:22 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_1(t_stack **stack_a, t_stack **stack_b, int index)
{
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
}

void	sort_5_2(t_stack **stack_a, t_stack **stack_b, int index)
{
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

int	sort_5_0(t_stack *tmp, t_stack **stack_a, int index)
{
	int	i;
	int	nb;

	i = 1;
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
	return (index);
}
