/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:04:04 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/14 20:04:49 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_stack_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
