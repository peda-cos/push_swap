#include "push_swap.h"

void	rotate_stack_up(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_a(t_list **stack_a)
{
	rotate_stack_up(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	rotate_stack_up(stack_b);
	ft_printf("rb\n");
}

void	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	rotate_stack_up(stack_a);
	rotate_stack_up(stack_b);
	ft_printf("rr\n");
}
