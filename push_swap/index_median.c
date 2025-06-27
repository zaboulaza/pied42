/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_median.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:22:38 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/26 09:53:34 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	int		i;

	if (*stack_a)
	{
		i = 1;
		first_a = *stack_a;
		while (first_a != NULL)
		{
			first_a->index = i;
			i++;
			first_a = first_a->next;
		}
	}
	index_b(stack_b);
}

void	index_b(t_stack **stack_b)
{
	t_stack	*first_b;
	int		j;

	if (*stack_b)
	{
		j = 1;
		first_b = *stack_b;
		while (first_b != NULL)
		{
			first_b->index = j;
			j++;
			first_b = first_b->next;
		}
	}
}
