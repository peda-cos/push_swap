/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by peda-cos          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

/* Stack utils */
t_stack	*new_node(int value);
void	stack_add_bottom(t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);

/* Operations - swap */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

/* Operations - push */
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

/* Operations - rotate */
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

/* Operations - reverse rotate */
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* Parsing */
t_stack	*parse_args(int argc, char **argv);
void	error_exit(t_stack **a);

/* Parsing utils */
int		is_valid_int(char *str);
int		has_duplicate(t_stack *stack, int value);
int		validate_arg(char *str, t_stack *stack, long *value);

/* Sort utils */
int		is_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int		get_position(t_stack *stack, t_stack *node);

/* Sort small */
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);

/* Sort turk */
void	turk_sort(t_stack **a, t_stack **b);

/* Sort turk utils */
void	set_targets(t_stack *a, t_stack *b);
t_stack	*get_cheapest(t_stack *b, t_stack *a);
void	execute_move(t_stack **a, t_stack **b, t_stack *cheapest);

#endif
