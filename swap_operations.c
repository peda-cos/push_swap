/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:52:14 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/14 19:52:17 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two_elements(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_a(t_list **stack_a)
{
	swap_top_two_elements(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	swap_top_two_elements(stack_b);
	ft_printf("sb\n");
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap_top_two_elements(stack_a);
	swap_top_two_elements(stack_b);
	ft_printf("ss\n");
}
