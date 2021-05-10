/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:41:22 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/10 19:12:13 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strtok_ps(char *str, char delim)
{
	while (*str)
	{
		if (*str == delim)
		{
			while (*str == delim)
			{
				*str = 0;
				str++;
			}
			return (str);
		}
		str++;
	}
	return (0);
}

int	ft_atoi(char *num)
{
	int		new_num;
	int		neg;

	new_num = 0;
	neg = 1;
	if (*num == '-')
	{
		neg = -1;
		num++;
	}
	while (ft_isdigit(*num))
	{
		new_num *= 10;
		new_num += *num - 48;
		num++;
	}
	new_num *= neg;
	return (new_num);
}

void	fill_stack_loop(int i, t_stack **stack, char **argv)
{
	char	*tmp;

	tmp = argv[i];
	if ((tmp = ft_strtok_ps(tmp, ' ')) != 0)
	{
		if (!*stack)
			*stack = ft_stknew(ft_atoi(argv[i]));
		else
			ft_stkadd_back(stack, ft_stknew(ft_atoi(argv[i])));
		ft_stkadd_back(stack, ft_stknew(ft_atoi(tmp)));
		while ((tmp = ft_strtok_ps(tmp, ' ')) != 0)
			ft_stkadd_back(stack, ft_stknew(ft_atoi(tmp)));
	}
	else
	{
		if (!*stack)
			*stack = ft_stknew(ft_atoi(argv[i]));
		else
			ft_stkadd_back(stack, ft_stknew(ft_atoi(argv[i])));
	}
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = 0;
	i = 1;
	while (i < argc)
	{
		fill_stack_loop(i, &stack, argv);
		i++;
	}
	return (stack);
}

int	check_order(t_stack *stack)
{
	int		num;

	num = INT_MIN;
	while (stack)
	{
		if (stack->num > num)
			num = stack->num;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}
