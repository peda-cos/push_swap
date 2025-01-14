#include "push_swap.h"

void	reverse_rotate_stack_down(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate_stack_down(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate_stack_down(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_stack_down(stack_a);
	reverse_rotate_stack_down(stack_b);
	ft_printf("rrr\n");
}
