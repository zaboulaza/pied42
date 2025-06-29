/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_median.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:22:38 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/29 01:58:37 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	int		i;
	int		k;
	int		size;

	size = size_(stack_a);
	if (*stack_a)
	{
		i = 0;
		k = 1;
		first_a = *stack_a;
		cut_index_a(first_a, i, size, k);
	}
	index_b(stack_b);
}

void	cut_index_a(t_stack *first_a, int i, int size, int k)
{
	int	j;

	if (size % 2 == 0)
		k++;
	while (first_a != NULL)
	{
		if (i > size / 2)
		{
			first_a->up_down = -1;
			j = i;
			j = j - k++;
			first_a->index = j;
			first_a = first_a->next;
		}
		else
		{
			first_a->up_down = 1;
			first_a->index = i;
			i++;
			first_a = first_a->next;
		}
	}
}

void	index_b(t_stack **stack_b)
{
	t_stack	*first_b;
	int		i;
	int		k;
	int		size;

	size = size_(stack_b);
	if (*stack_b)
	{
		i = 0;
		k = 1;
		first_b = *stack_b;
		cut_index_b(first_b, i, size, k);
	}
}

void	cut_index_b(t_stack *first_b, int i, int size, int k)
{
	int	j;

	if (size % 2 == 0)
		k++;
	while (first_b != NULL)
	{
		if (i > size / 2)
		{
			first_b->up_down = -1;
			j = i;
			j = j - k++;
			first_b->index = j;
			first_b = first_b->next;
		}
		else
		{
			first_b->up_down = 1;
			first_b->index = i;
			i++;
			first_b = first_b->next;
		}
	}
}

int	size_(t_stack **tmp)
{
	t_stack	*tmp_;
	int		size;

	tmp_ = *tmp;
	size = 0;
	while (tmp_ != NULL)
	{
		size++;
		tmp_ = tmp_->next;
	}
	return (size);
}
