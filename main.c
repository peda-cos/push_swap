#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int	*arr;
	int	top;
	int	size;
}		t_stack;

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = (int *)malloc(sizeof(int) * size);
	if (!stack->arr)
		return (NULL);
	stack->top = -1;
	stack->size = size;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	if (stack->top < stack->size - 1)
	{
		stack->arr[++(stack->top)] = value;
	}
}

int	pop(t_stack *stack)
{
	if (stack->top >= 0)
	{
		return (stack->arr[(stack->top)--]);
	}
	return (INT_MIN);
}

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->top > 0)
	{
		temp = stack->arr[stack->top];
		stack->arr[stack->top] = stack->arr[stack->top - 1];
		stack->arr[stack->top - 1] = temp;
	}
}

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top > 0)
	{
		temp = stack->arr[0];
		i = 0;
		while (i < stack->top)
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
		stack->arr[stack->top] = temp;
	}
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top > 0)
	{
		temp = stack->arr[stack->top];
		i = stack->top;
		while (i > 0)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
		stack->arr[0] = temp;
	}
}

void	partition(t_stack *a, t_stack *b, int pivot)
{
	int	temp;

	while (a->top >= 0)
	{
		if (a->arr[a->top] < pivot)
		{
			push(b, pop(a));
			printf("pb\n");
		}
		else
		{
			rotate(a);
			printf("ra\n");
		}
	}
}

void	quicksort(t_stack *a, t_stack *b)
{
	int	pivot;

	if (a->top <= 0)
		return ;
	pivot = a->arr[0];
	partition(a, b, pivot);
	quicksort(a, b);
	quicksort(b, a);
	while (b->top >= 0)
	{
		push(a, pop(b));
		printf("pa\n");
	}
}

int	is_valid_input(int argc, char *argv[])
{
	int	i;
	int	j;

	for (i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				return (0);
			j++;
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc < 2)
	{
		printf("Error: Not enough arguments\n");
		return (1);
	}
	if (!is_valid_input(argc, argv))
	{
		printf("Error: Invalid input\n");
		return (1);
	}
	a = init_stack(argc - 1);
	b = init_stack(argc - 1);
	if (!a || !b)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		push(a, atoi(argv[i]));
	}
	quicksort(a, b);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}
