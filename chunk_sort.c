/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:53:40 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/15 16:59:22 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_chunk(t_list **stack_a, t_list **stack_b, int chunk_start,
		int chunk_size)
{
	int	count;
	int	current_index;
	int	chunk_end;

	count = 0;
	chunk_end = chunk_start + chunk_size - 1;
	while (count < chunk_size && ft_lstsize(*stack_a) > 0)
	{
		current_index = *(int *)(*stack_a)->index;
		if (current_index >= chunk_start && current_index <= chunk_end)
		{
			push_to_b(stack_a, stack_b);
			if (*(int *)(*stack_b)->index < (chunk_start + chunk_end) / 2)
				rotate_b(stack_b);
			count++;
		}
		else
			rotate_a(stack_a);
	}
}

static void	move_remaining(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 0)
	{
		push_to_b(stack_a, stack_b);
		if (*stack_a && (*(int *)(*stack_b)->index < *(int *)(*stack_a)->index))
			rotate_b(stack_b);
	}
}

static void	return_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_pos;

	while (*stack_b)
	{
		max_pos = find_max_position(*stack_b);
		move_max_to_top(stack_b, max_pos);
		push_to_a(stack_a, stack_b);
	}
}

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunks;
	int	chunk_size;
	int	chunk_start;
	int	c;

	size = ft_lstsize(*stack_a);
	if (size <= 100)
		chunks = 5;
	else
		chunks = 11;
	chunk_size = size / chunks;
	chunk_start = 0;
	c = 0;
	while (c < chunks)
	{
		process_chunk(stack_a, stack_b, chunk_start, chunk_size);
		chunk_start += chunk_size;
		c++;
	}
	move_remaining(stack_a, stack_b);
	return_to_a(stack_a, stack_b);
}
