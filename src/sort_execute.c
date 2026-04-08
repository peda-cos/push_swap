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

#include "../include/push_swap.h"

static void	rotate_both_fwd(t_stack **a, t_stack **b, t_stack *node)
{
	while (*b != node && *a != node->target)
		rr(a, b, 1);
	while (*b != node)
		rb(b, 1);
	while (*a != node->target)
		ra(a, 1);
}

static void	rotate_both_rev(t_stack **a, t_stack **b, t_stack *node)
{
	while (*b != node && *a != node->target)
		rrr(a, b, 1);
	while (*b != node)
		rrb(b, 1);
	while (*a != node->target)
		rra(a, 1);
}

static void	rotate_separate(t_stack **a, t_stack **b, t_stack *node)
{
	int	b_pos;
	int	a_pos;
	int	b_size;
	int	a_size;

	b_size = stack_size(*b);
	a_size = stack_size(*a);
	b_pos = get_position(*b, node);
	a_pos = get_position(*a, node->target);
	while (*b != node)
	{
		if (b_pos <= b_size / 2)
			rb(b, 1);
		else
			rrb(b, 1);
	}
	while (*a != node->target)
	{
		if (a_pos <= a_size / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	execute_move(t_stack **a, t_stack **b, t_stack *node)
{
	int	b_pos;
	int	a_pos;
	int	b_size;
	int	a_size;

	b_size = stack_size(*b);
	a_size = stack_size(*a);
	b_pos = get_position(*b, node);
	a_pos = get_position(*a, node->target);
	if (b_pos <= b_size / 2 && a_pos <= a_size / 2)
		rotate_both_fwd(a, b, node);
	else if (b_pos > b_size / 2 && a_pos > a_size / 2)
		rotate_both_rev(a, b, node);
	else
		rotate_separate(a, b, node);
	pa(a, b, 1);
}
