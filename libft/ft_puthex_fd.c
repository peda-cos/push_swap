/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:04:45 by peda-cos          #+#    #+#             */
/*   Updated: 2024/10/24 01:17:11 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthex(unsigned int n, const char *base, int fd)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, base, fd);
	count += ft_putchar_fd(base[n % 16], fd);
	return (count);
}

int	ft_puthex_fd(unsigned int n, int uppercase, int fd)
{
	if (uppercase)
		return (ft_puthex(n, "0123456789ABCDEF", fd));
	else
		return (ft_puthex(n, "0123456789abcdef", fd));
}
