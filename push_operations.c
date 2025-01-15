/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:48:49 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/14 19:55:23 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element(t_list **dest_stack, t_list **src_stack)
{
	t_list	*temp;

	if (!src_stack || !*src_stack)
		return ;
	temp = *src_stack;
	*src_stack = (*src_stack)->next;
	temp->next = *dest_stack;
	*dest_stack = temp;
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	push_element(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	push_element(stack_b, stack_a);
	ft_printf("pb\n");
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b, int pushed)
{
	int	max_pos;

	while (pushed > 0)
	{
		max_pos = find_max_position(*stack_b);
		move_max_to_top(stack_b, max_pos);
		push_to_a(stack_a, stack_b);
		pushed--;
	}
}

void	push_min_to_b(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	size;

	size = ft_lstsize(*stack_a);
	min_pos = find_min_position(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			rotate_a(stack_a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			reverse_rotate_a(stack_a);
			min_pos++;
		}
	}
	push_to_b(stack_a, stack_b);
}
