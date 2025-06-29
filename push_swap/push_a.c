/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 05:46:28 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/29 06:07:01 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    tmp = *stack_b;
    while (tmp)
    {
        pa(stack_a, stack_b);
    }
}
