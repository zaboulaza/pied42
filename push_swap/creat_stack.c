/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:07:59 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/29 03:17:06 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pimp(t_stack *head) {

	t_stack	*tmp;
	
	tmp = head;
	printf("stack pimp:\t");
	while (tmp) {
		
		printf("%d ", tmp->nb);
		tmp = tmp->next;
	}
	printf("\n");
	
}

void	print_list_a(t_stack *head)
{
	t_stack	*tmp;
	int		nb;
	int		i;

	i = 1;
	tmp = head;
	printf("A: ");
	while (tmp)
	{
		nb = tmp->nb;
		printf("index : [%d] --->  liste : [%d]\n", tmp->index, tmp->nb);
		printf("index : [%d] --->  adress target : [%p]\n", tmp->index,
			tmp->target);
		printf("index : [%d] --->  mon adress : [%p]\n", tmp->index, tmp);
		printf("index : [%d] --->  count : [%d]\n", tmp->index, tmp->count);
		printf("index : [%d] --->  up_down : [%d]\n", tmp->index, tmp->up_down);
		printf("\n");
		i++;
		tmp = tmp->next;
	}
	
	// printf("a\t");
	// while (tmp) {
	// 	nb = tmp->nb;
	// 	printf("%d ", tmp->nb);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	
}

void	print_list_b(t_stack *head)
{
	t_stack	*tmp;
	int		nb;
	int		i;

	i = 1;
	tmp = head;
	printf("B: ");
	while (tmp)
	{
		nb = tmp->nb;
		printf("index : [%d] --->  liste : [%d]\n", tmp->index, tmp->nb);
		printf("index : [%d] --->  adress target : [%p]\n", tmp->index,
			tmp->target);
		printf("index : [%d] --->  mon adress : [%p]\n", tmp->index, tmp);
		printf("index : [%d] --->  count : [%d]\n", tmp->index, tmp->count);
		printf("index : [%d] --->  up_down : [%d]\n", tmp->index, tmp->up_down);
		printf("\n");
		i++;
		tmp = tmp->next;
	}

	// tmp = head;
	// printf("b\t");
	// while (tmp) {
	// 	nb = tmp->nb;
	// 	printf("%d ", tmp->nb);
	// 	tmp = tmp->next;

	// }
	// printf("\n");
}

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
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = ft_atoi(value);
	if (!(node->nb >= INT_MIN && node->nb <= INT_MAX))
	{
		free(node);
		return (NULL);
	}
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
