/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:52:30 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/26 21:12:21 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	contains_duplicate(long num, int current_index, char **argv)
{
	int		j;
	long	prev_num;

	j = 1;
	while (j < current_index)
	{
		if (!modified_atol(argv[j], &prev_num))
			return (1);
		if (num == prev_num)
			return (1);
		j++;
	}
	return (0);
}

static void	validate_inputs(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!modified_atol(argv[i], &num))
			exit_with_error(NULL, NULL);
		if (contains_duplicate(num, i, argv))
			exit_with_error(NULL, NULL);
		i++;
	}
}

static void	populate_stack(int argc, char **argv, t_list **stack_a)
{
	long	num;
	int		*content;
	int		i;

	i = 1;
	while (i < argc)
	{
		modified_atol(argv[i], &num);
		content = malloc(sizeof(int));
		if (!content)
			exit_with_error(stack_a, NULL);
		*content = (int)num;
		ft_lstadd_back(stack_a, ft_lstnew(content));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	validate_inputs(argc, argv);
	populate_stack(argc, argv, &stack_a);
	get_sort_index(stack_a);
	if (!is_stack_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
