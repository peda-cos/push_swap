#include "push_swap.h"

void	exit_with_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}