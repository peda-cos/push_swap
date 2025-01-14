#include "push_swap.h"

void	push_element(t_list **dest_stack, t_list **src_stack)
{
	t_list	*temp;

	if (!src_stack || !*src_stack)
		return ;
	temp = *src_stack;
	*src_stack = (*src_stack)->next;
	temp->next = *dest_stack;
	*dest_stack = temp;
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	push_element(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	push_element(stack_b, stack_a);
	ft_printf("pb\n");
}
