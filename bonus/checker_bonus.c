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

#include "checker_bonus.h"

static void	apply_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	line = read_line();
	while (line)
	{
		if (!execute_instruction(line, a, b))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(line);
		line = read_line();
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	apply_instructions(&a, &b);
	if (is_sorted(a) && !b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
