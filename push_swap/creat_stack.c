/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:07:59 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/24 19:08:34 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_liste(t_stack **head, char *value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = new_node(value);
	if (!new)
		return (1);
	if (!*head)
	{
		*head = new;
		return (0);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

t_stack	*new_node(char *value)
{
	t_stack		*node;
	long long	check_value;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	check_value = ft_atoll(value);
	if (!(check_value >= INT_MIN && check_value <= INT_MAX))
	{
		free(node);
		return (NULL);
	}
	node->nb = ft_atoi(value);
	node->next = NULL;
	node->target = NULL;
	return (node);
}

int	verif_same_nb(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*first;

	tmp = stack_a;
	first = stack_a;
	while (tmp)
	{
		first = first->next;
		stack_a = first;
		while (stack_a)
		{
			if (stack_a->nb == tmp->nb)
				return (1);
			stack_a = stack_a->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

long long	ft_atoll(const char *nb)
{
	int			i;
	int			neg;
	long long	res;

	res = 0;
	i = 0;
	neg = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			neg = 1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = (res * 10) + (nb[i] - '0');
		i++;
	}
	if (neg == 1)
		res = res * -1;
	return (res);
}
