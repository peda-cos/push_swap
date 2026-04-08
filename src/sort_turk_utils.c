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

static t_stack	*find_target(t_stack *a, int b_val)
{
	t_stack	*target;
	t_stack	*tmp;

	target = NULL;
	tmp = a;
	while (tmp)
	{
		if (tmp->value > b_val)
			if (!target || tmp->value < target->value)
				target = tmp;
		tmp = tmp->next;
	}
	if (!target)
		target = find_min(a);
	return (target);
}

void	set_targets(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = b;
	while (tmp)
	{
		tmp->target = find_target(a, tmp->value);
		tmp = tmp->next;
	}
}

static int	real_cost(t_stack *node, t_stack *a, t_stack *b)
{
	int	a_size;
	int	b_size;
	int	pos_a;
	int	pos_b;

	a_size = stack_size(a);
	b_size = stack_size(b);
	pos_b = get_position(b, node);
	pos_a = get_position(a, node->target);
	if (pos_b <= b_size / 2 && pos_a <= a_size / 2)
	{
		if (pos_b > pos_a)
			return (pos_b + 1);
		return (pos_a + 1);
	}
	if (pos_b > b_size / 2 && pos_a > a_size / 2)
	{
		if ((b_size - pos_b) > (a_size - pos_a))
			return (b_size - pos_b + 1);
		return (a_size - pos_a + 1);
	}
	if (pos_b <= b_size / 2)
		return (pos_b + (a_size - pos_a) + 1);
	return ((b_size - pos_b) + pos_a + 1);
}

t_stack	*get_cheapest(t_stack *b, t_stack *a)
{
	t_stack	*cheapest;
	t_stack	*b_head;
	int		min_cost;
	int		cost;

	cheapest = NULL;
	min_cost = INT_MAX;
	b_head = b;
	while (b)
	{
		cost = real_cost(b, a, b_head);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}
