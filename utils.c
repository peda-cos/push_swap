/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:04:04 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/26 20:19:30 by peda-cos         ###   ########.fr       */
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

static int	is_space_or_sign(const char **str, int *sign)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
	if (!ft_isdigit(**str))
		return (0);
	return (1);
}

static int	is_overflow(long temp, int digit, int sign)
{
	if (sign == 1 && temp > (LONG_MAX - digit) / 10)
		return (1);
	if (sign == -1 && -temp < (LONG_MIN + digit) / 10)
		return (1);
	return (0);
}

int	ft_atol(const char *str, long *num)
{
	int		sign;
	long	temp;
	int		digit;

	sign = 1;
	if (!is_space_or_sign(&str, &sign))
		return (0);
	temp = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		digit = *str - '0';
		if (is_overflow(temp, digit, sign))
			return (0);
		temp = temp * 10 + digit;
		str++;
	}
	*num = temp * sign;
	if (*num > INT_MAX || *num < INT_MIN)
		return (0);
	return (1);
}
