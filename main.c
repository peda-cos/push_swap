#include "push_swap.h"

static void	exit_with_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	is_valid_integer(const char *str, long long *num)
{
	int			i;
	long long	temp;

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
	t_list		*stack_a;
	t_list		*stack_b;
	long long	num;
	int			*content;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (argc > 1)
	{
		if (!is_valid_integer(argv[argc - 1], &num)
			|| contains_duplicate(stack_a, num))
			exit_with_error(&stack_a, &stack_b);
		content = (int *)malloc(sizeof(int));
		if (!content)
			exit_with_error(&stack_a, &stack_b);
		*content = num;
		ft_lstadd_front(&stack_a, ft_lstnew(content));
		argc--;
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
