/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 03:40:30 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/29 06:03:43 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack **stack_b)
{
	t_stack	*tmp;
	int		max;
	int		pos;
	int		i;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	max = tmp->nb;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->nb > max)
		{
			max = tmp->nb;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	mouve_top(pos, stack_b);
}

void mouve_top(int pos, t_stack **stack_b)
{
	if (pos <= size_(stack_b) / 2)
	{
		while (pos-- > 0)
			rb(stack_b);
	}
	else
	{
		pos = size_(stack_b) - pos;
		while (pos-- > 0)
			rrb(stack_b);
	}
}