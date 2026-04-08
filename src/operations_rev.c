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

static void	rev_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	rra(t_stack **a, int print)
{
	rev_rotate(a);
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b, int print)
{
	rev_rotate(b);
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_putendl_fd("rrr", 1);
}
