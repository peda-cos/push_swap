/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:51:44 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/14 22:31:09 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack_a)->content;
	second = *(int *)(*stack_a)->next->content;
	third = *(int *)(*stack_a)->next->next->content;
	if (first > second && second > third)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (first > second && first > third)
		rotate_a(stack_a);
	else if (first > second)
		swap_a(stack_a);
	else if (second > third && first > third)
		reverse_rotate_a(stack_a);
	else if (second > third)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
}

void	sort_five_elements(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size - 3)
	{
		push_min_to_b(stack_a, stack_b);
		i++;
	}
	sort_three_elements(stack_a);
	while (*stack_b)
		push_to_a(stack_a, stack_b);
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size - 3)
	{
		push_min_to_b(stack_a, stack_b);
		i++;
	}
	sort_three_elements(stack_a);
	while (*stack_b)
		push_to_a(stack_a, stack_b);
}

void	quick_sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	median;
	int	pushed;

	median = get_stack_median(*stack_a);
	pushed = 0;
	size = ft_lstsize(*stack_a);
	while (size > 0)
	{
		if (*(*stack_a)->index < median)
		{
			if (*(*stack_a)->index < median / 2)
				push_and_rotate(stack_a, stack_b);
			else
				push_to_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
		size--;
	}
	if (!is_stack_sorted(*stack_a))
		quick_sort_stack(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b, pushed);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_three_elements(stack_a);
	else if (size == 5)
		sort_five_elements(stack_a, stack_b);
	else if (size <= 10)
		sort_small_stack(stack_a, stack_b);
	else
		quick_sort_stack(stack_a, stack_b);
}
