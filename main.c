/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:52:30 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/14 20:04:57 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_integer(const char *str, long *num)
{
	int		i;
	long	temp;

	i = 0;
	if (ft_isspace(str[i]))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	temp = ft_atoi(str);
	if (temp > INT_MAX || temp < INT_MIN)
		return (0);
	*num = temp;
	return (1);
}

static int	contains_duplicate(t_list *stack, int num)
{
	while (stack)
	{
		if (*(int *)stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	long	num;
	int		*content;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (argc > 1)
	{
		argc--;
		if (!is_valid_integer(argv[argc], &num) || contains_duplicate(stack_a,
				num))
			exit_with_error(NULL, NULL);
		content = (int *)malloc(sizeof(int));
		if (!content)
			exit_with_error(NULL, NULL);
		*content = num;
		ft_lstadd_front(&stack_a, ft_lstnew(content));
	}
	get_sort_index(stack_a);
	if (!is_stack_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
