#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

void	exit_with_error(t_list **stack_a, t_list **stack_b);
int		is_valid_integer(const char *str, long long *num);
void	rotate_stack_up(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_stack_down(t_list **stack);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);

#endif