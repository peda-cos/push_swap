/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:52:08 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/14 19:52:10 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(t_list *stack_b)
{
	t_list	*current;
	int		max_index;
	int		max_pos;
	int		pos;

	max_index = -1;
	max_pos = 0;
	pos = 0;
	current = stack_b;
	while (current)
	{
		if (*current->index > max_index)
		{
			max_index = *current->index;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

void	move_max_to_top(t_list **stack_b, int max_pos)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (max_pos <= size / 2)
	{
		while (max_pos > 0)
		{
			rotate_b(stack_b);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < size)
		{
			reverse_rotate_b(stack_b);
			max_pos++;
		}
	}
}

void	push_and_rotate(t_list **stack_a, t_list **stack_b)
{
	push_to_b(stack_a, stack_b);
	rotate_b(stack_b);
}

int	find_min_position(t_list *stack)
{
	t_list	*current;
	int		min;
	int		min_pos;
	int		pos;

	current = stack;
	min = *(int *)current->content;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (*(int *)current->content < min)
		{
			min = *(int *)current->content;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}
