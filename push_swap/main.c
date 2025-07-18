/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 02:59:43 by nsmail            #+#    #+#             */
/*   Updated: 2025/07/02 20:31:39 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_general	g;

	if (ac < 2)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	creat_struct(&g);
	if (parcing_1(&g, av) == 1)
	{
		free_struct(&g);
		return (1);
	}
	algo_main(&g);
	free_struct(&g);
	return (1);
}

void	creat_struct(t_general *g)
{
	ft_memset(g, 0, sizeof(t_general));
	g->prcg = ft_calloc(1, sizeof(t_parcing));
	if (!g->prcg)
		exit(1);
	g->stack = ft_calloc(1, sizeof(t_stack));
	if (!g->stack)
	{
		free_struct(g);
		exit(1);
	}
	ft_memset(g->stack, 0, sizeof(t_stack));
	g->stacks = ft_calloc(1, sizeof(t_stacks));
	if (!g->stacks)
	{
		free_struct(g);
		exit(1);
	}
	ft_memset(g->stacks, 0, sizeof(t_stacks));
}

void	free_struct(t_general *g)
{
	int	i;

	i = 0;
	if (g->stack)
		free(g->stack);
	if (g->prcg)
	{
		if (g->prcg->arg_join)
			free(g->prcg->arg_join);
		free(g->prcg);
	}
	if (g->stacks)
	{
		if (g->stacks->stack_a)
			free_list(g->stacks->stack_a);
		if (g->stacks->stack_b)
			free_list(g->stacks->stack_b);
		free(g->stacks);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_list(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
