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

static void	swap_top(t_stack **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_stack **a, int print)
{
	swap_top(a);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b, int print)
{
	swap_top(b);
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap_top(a);
	swap_top(b);
	if (print)
		ft_putendl_fd("ss", 1);
}
