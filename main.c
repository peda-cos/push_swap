#include "push_swap.h"

void	exit_with_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_valid_integer(const char *str, long long *num)
{
	int			i;
	long long	temp;

	i = 0;
	if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	temp = ft_atoi(str);
	if (temp > INT_MAX || temp < INT_MIN)
		return (0);
	*num = temp;
	return (1);
}
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}