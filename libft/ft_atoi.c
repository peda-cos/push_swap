/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:33:46 by peda-cos          #+#    #+#             */
/*   Updated: 2024/12/28 20:27:52 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	digit;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (sign == 1 && (result > (2147483647 - digit) / 10))
			return (2147483647);
		if (sign == -1 && (-result < (-2147483648 + digit) / 10))
			return (-2147483648);
		result = result * 10 + digit;
		nptr++;
	}
	return (sign * result);
}

unsigned int	get_idx_base(char in_ch, char *b_str)
{
	unsigned int	b_idx;

	b_idx = 0;
	while (ft_toupper(b_str[b_idx]) != '\0'
		&& ft_toupper(b_str[b_idx]) != ft_toupper(in_ch))
	{
		b_idx++;
	}
	return (b_idx);
}

unsigned int	ft_atoi_base(const char *s_str, char *b_str)
{
	unsigned int	cnv_nb;
	size_t			s_idx;
	size_t			b_len;

	s_idx = 0;
	cnv_nb = 0;
	b_len = ft_strlen(b_str);
	if (ft_strnstr(s_str, "0x", ft_strlen(s_str)) != NULL)
	{
		s_idx = 2;
	}
	if (s_idx <= ft_strlen(s_str))
	{
		while (s_str[s_idx] != '\0')
		{
			cnv_nb = cnv_nb * b_len + get_idx_base(s_str[s_idx], b_str);
			s_idx++;
		}
	}
	return (cnv_nb);
}
