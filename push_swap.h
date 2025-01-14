#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

void	push_element(t_list **dest_stack, t_list **src_stack);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);

void	swap_top_two_elements(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);

void	rotate_stack_up(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);

void	reverse_rotate_stack_down(t_list **stack);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);

#endif