/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 03:02:15 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/27 19:38:17 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stdbool.h"
# include "stdio.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				nb;
	// int				count;
	int				index;
	bool			up_median;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_stacks;

typedef struct s_parcing
{
	char			**nb_str;
	char			*arg_join;
}					t_parcing;

typedef struct s_general
{
	t_parcing		*prcg;
	t_stacks		*stacks;
	t_stack			*stack;
}					t_general;

// ------------------------- BASE ------------------------//
int					main(int ac, char **av);
int					parcing_1(t_general *g, char **av);
void				creat_struct(t_general *g);
int					join_line(t_general *g, char **av);

// ------------------------- PARSING ------------------------//
int					verif_good_format(t_general *g);
int					verif_good_cara(char *s);
int					split_number(t_general *g);
int					verif_same_nb(t_stack *stack_a);
void				put_index(t_stack **stack_a, t_stack **stack_b);
void				index_b(t_stack **stack_b);
void				algo_main(t_general *g);
void				push_3(t_stack **stack_a, t_stack **stack_b);
void				push_3_1(t_stack **stack_a, t_stack **stack_b);
void				target_g(t_stack **stack_a, t_stack **stack_b);
void				target_b(t_stack *first_a, t_stack *tmp_b);
void				target_a(t_stack *first_a, t_stack *first_b);

// ------------------------- FREE ------------------------//
void				free_struct(t_general *g);
void				free_tab(char **tab);
void				free_list(t_stack *stack);

// ------------------------- LISTE ------------------------//
t_stack				*new_node(char *value);
int					add_to_liste(t_stack **head, char *value);

// -------------------- LISTE : UTILS --------------------//
// ------------------------- SWAP ------------------------//
int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);

// ------------------------- PUSH ------------------------//
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);

// ------------------------- ROTATE ------------------------//
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);

// -------------------------REVERSE ROTATE ------------------------//
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);

// ------------------------- FONCTION TEST ------------------------//
void				print_list(t_stack *head);

#endif