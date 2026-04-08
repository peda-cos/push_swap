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

static void	push_all_but_three(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;

	size = stack_size(*a);
	pushed = 0;
	while (size - pushed > 3)
	{
		pb(a, b, 1);
		pushed++;
	}
}

static void	rotate_min_to_top(t_stack **a)
{
	t_stack	*min;
	int		pos;
	int		size;

	min = find_min(*a);
	pos = get_position(*a, min);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (*a != min)
			ra(a, 1);
	}
	else
	{
		while (*a != min)
			rra(a, 1);
	}
}

static void	update_and_push(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	set_targets(*a, *b);
	cheapest = get_cheapest(*b, *a);
	execute_move(a, b, cheapest);
}

void	turk_sort(t_stack **a, t_stack **b)
{
	push_all_but_three(a, b);
	sort_three(a);
	while (*b)
		update_and_push(a, b);
	rotate_min_to_top(a);
}
