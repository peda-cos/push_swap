/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:27:34 by peda-cos          #+#    #+#             */
/*   Updated: 2024/10/15 10:02:17 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
	int	i;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	count = 0;
	i = 0;
	while (s[i])
	{
		count += ft_putchar_fd(s[i], fd);
		i++;
	}
	return (count);
}
