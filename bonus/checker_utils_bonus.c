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

static char	*grow_buf(char *buf, int *cap)
{
	char	*new_buf;
	int		i;

	*cap = *cap * 2;
	new_buf = malloc(*cap);
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (buf[i])
	{
		new_buf[i] = buf[i];
		i++;
	}
	new_buf[i] = '\0';
	free(buf);
	return (new_buf);
}

static char	*append_char(char *buf, int *len, int *cap, char c)
{
	if (*len + 1 >= *cap)
	{
		buf = grow_buf(buf, cap);
		if (!buf)
			return (NULL);
	}
	buf[(*len)++] = c;
	buf[*len] = '\0';
	return (buf);
}

char	*read_line(void)
{
	char	*buf;
	int		len;
	int		cap;
	char	c;
	int		ret;

	cap = 8;
	len = 0;
	buf = malloc(cap);
	if (!buf)
		return (NULL);
	ret = read(0, &c, 1);
	while (ret > 0 && c != '\n')
	{
		buf = append_char(buf, &len, &cap, c);
		if (!buf)
			return (NULL);
		ret = read(0, &c, 1);
	}
	if (ret <= 0 && !len)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

static int	is_same(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == '\0' && b[i] == '\0');
}

int	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (is_same(line, "sa"))
		sa(a, 0);
	else if (is_same(line, "sb"))
		sb(b, 0);
	else if (is_same(line, "ss"))
		ss(a, b, 0);
	else if (is_same(line, "pa"))
		pa(a, b, 0);
	else if (is_same(line, "pb"))
		pb(a, b, 0);
	else if (is_same(line, "ra"))
		ra(a, 0);
	else if (is_same(line, "rb"))
		rb(b, 0);
	else if (is_same(line, "rr"))
		rr(a, b, 0);
	else if (is_same(line, "rra"))
		rra(a, 0);
	else if (is_same(line, "rrb"))
		rrb(b, 0);
	else if (is_same(line, "rrr"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}
