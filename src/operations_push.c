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

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = *dst;
	*dst = node;
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	push(b, a);
	if (print)
		ft_putendl_fd("pb", 1);
}
