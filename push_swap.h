/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:49:05 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/20 08:20:24 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

void	exit_with_error(t_list **stack_a, t_list **stack_b);
int		is_stack_sorted(t_list *stack);
int		is_valid_integer(const char *str, long *num);

void	push_element(t_list **dest_stack, t_list **src_stack);
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	push_back_to_a(t_list **stack_a, t_list **stack_b, int pushed);
void	push_min_to_b(t_list **stack_a, t_list **stack_b);

void	swap_top_two_elements(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_b(t_list **stack_a, t_list **stack_b);

void	rotate_stack_up(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);

void	reverse_rotate_stack_down(t_list **stack);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_a_b(t_list **stack_a, t_list **stack_b);

int		*create_index_array(t_list *stack, int size);
void	sort_index_array(int *array, int size);
void	assign_sorted_index(int *sorted_array, t_list *stack, int size);
void	get_sort_index(t_list *stack);

int		find_max_position(t_list *stack_b);
void	move_max_to_top(t_list **stack_b, int max_pos);
int		find_min_position(t_list *stack);

void	sort_three_elements(t_list **stack_a);
void	sort_five_elements(t_list **stack_a, t_list **stack_b);
void	sort_small_stack(t_list **stack_a, t_list **stack_b);
void	chunk_sort(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **stack_a, t_list **stack_b);

#endif
