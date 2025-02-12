/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:51:53 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/20 08:16:08 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_index_array(t_list *stack, int size)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i] = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	sort_index_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	assign_sorted_index(int *sorted_array, t_list *stack, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)stack->content == sorted_array[i])
			{
				stack->index = (int *)malloc(sizeof(int));
				if (!stack->index)
					exit_with_error(&stack, NULL);
				*stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	get_sort_index(t_list *stack)
{
	int	*array;
	int	size;

	size = ft_lstsize(stack);
	array = create_index_array(stack, size);
	if (!array)
		exit_with_error(NULL, NULL);
	sort_index_array(array, size);
	assign_sorted_index(array, stack, size);
	free(array);
}
