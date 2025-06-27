/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:02:50 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/27 17:12:32 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_main(t_general *g)
{
	push_3(&g->stacks->stack_a, &g->stacks->stack_b);
	put_index(&g->stacks->stack_a, &g->stacks->stack_b);
	target_g(&g->stacks->stack_a, &g->stacks->stack_b);
	print_list(g->stacks->stack_a);
	printf("\n");
	printf("\n");
	printf("\n");
	print_list(g->stacks->stack_b);
}

void	push_3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack_a;
	second = first->next;
	third = second->next;
	if (first->nb > second->nb && second->nb > third->nb
		&& first->nb > third->nb)
	{
		sa(stack_a);
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
		sa(stack_a);
	}
	else if (first->nb < second->nb && second->nb > third->nb
		&& first->nb > third->nb)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
		sa(stack_a);
	}
	push_3_1(stack_a, stack_b);
}

void	push_3_1(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*fir;
	t_stack	*sec;
	t_stack	*third;

	fir = *stack_a;
	sec = fir->next;
	third = sec->next;
	if (fir->nb > sec->nb && sec->nb < third->nb && fir->nb > third->nb)
	{
		sa(stack_a);
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (fir->nb < sec->nb && sec->nb > third->nb && fir->nb < third->nb)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (fir->nb > sec->nb && sec->nb < third->nb && fir->nb < third->nb)
		sa(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}
