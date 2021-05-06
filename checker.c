/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:40:42 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/06 19:06:26 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_arg_2(char *line, t_stack **stack_a, t_stack **stack_b)
{
	int		len;

	len = ft_strlen(line);
	if (len == 2 && !ft_memcmp("rb", line, len))
		ft_stkrotate(stack_b);
	else if (len == 2 && !ft_memcmp("rr", line, len))
	{
		ft_stkrotate(stack_a);
		ft_stkrotate(stack_b);
	}
	else if (len == 3 && !ft_memcmp("rra", line, len))
		ft_stkrotate_rev(stack_a);
	else if (len == 3 && !ft_memcmp("rrb", line, len))
		ft_stkrotate_rev(stack_b);
	else if (len == 3 && !ft_memcmp("rrr", line, len))
	{
		ft_stkrotate_rev(stack_a);
		ft_stkrotate_rev(stack_b);
	}
	else
	{
		write(1, "Error\n", 6);
		exit (0);
	}
		
}

void	parse_arg(char *line, t_stack **stack_a, t_stack **stack_b)
{
	int		len;

	len = ft_strlen(line);
	if (len == 2 && !ft_memcmp("sa", line, len))
		ft_stkswap(*stack_a);
	else if (len == 2 && !ft_memcmp("sb", line, len))
		ft_stkswap(*stack_b);
	else if (len == 2 && !ft_memcmp("ss", line, len))
	{
		ft_stkswap(*stack_a);
		ft_stkswap(*stack_b);
	}
	else if (len == 2 && !ft_memcmp("pa", line, len))
		ft_stkpush(stack_a, stack_b);
	else if (len == 2 && !ft_memcmp("pb", line, len))
		ft_stkpush(stack_b, stack_a);
	else if (len == 2 && !ft_memcmp("ra", line, len))
		ft_stkrotate(stack_a);
	else
		parse_arg_2(line, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;

	while (get_next_line(1, &line))
	{
		parse_arg(line, &stack_a, &stack_b);
		free(line);
	}
	if (check_order(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (0);
}
