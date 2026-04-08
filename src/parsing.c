/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 00:00:00 by peda-cos          #+#    #+#             */
/*   Updated: 2026/04/08 00:00:00 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	add_token(t_stack **a, int value)
{
	t_stack	*node;

	node = new_node(value);
	if (!node)
		error_exit(a);
	stack_add_bottom(a, node);
}

static void	parse_single(t_stack **a, char *arg)
{
	char	**tokens;
	long	value;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		error_exit(a);
	i = 0;
	while (tokens[i])
	{
		if (!validate_arg(tokens[i], *a, &value))
			error_exit(a);
		add_token(a, (int)value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	if (argc < 2)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			error_exit(&a);
		parse_single(&a, argv[i]);
		i++;
	}
	return (a);
}
