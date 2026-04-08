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

int	is_valid_int(char *str)
{
	int	i;
	int	digits;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	digits = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		digits++;
		if (digits > 10)
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	error_exit(t_stack **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	validate_arg(char *str, t_stack *stack, long *value)
{
	if (!is_valid_int(str))
		return (0);
	*value = ft_atol(str);
	if (*value > INT_MAX || *value < INT_MIN)
		return (0);
	if (has_duplicate(stack, (int)*value))
		return (0);
	return (1);
}
