/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:41:22 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/25 19:07:27 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strtok_ps(char *str, char delim)
{
	while (*str == delim)
		str++;
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
	long	i_num;
	int		neg;

	i_num = 0;
	neg = 1;
	while (*num == ' ')
		num++;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			neg *= -1;
		num++;
	}
	if (!(*num))
		error_exit();
	while (*num && *num != ' ')
	{
		i_num *= 10;
		i_num += *num - 48;
		if (!ft_isdigit(*num) || (i_num * neg) != (int)(i_num * neg))
			error_exit();
		num++;
	}
	return (i_num * neg);
}

void	fill_stack_loop(int i, t_stack **stack, char **argv)
{
	char	*tmp;

	if (!*stack)
		*stack = ft_stknew(ft_atoi(argv[i]));
	else
		ft_stkadd_back(stack, ft_stknew(ft_atoi(argv[i])));
	tmp = ft_strtok_ps(argv[i], ' ');
	while (tmp != 0)
	{
		ft_stkadd_back(stack, ft_stknew(ft_atoi(tmp)));
		tmp = ft_strtok_ps(tmp, ' ');
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
	if (check_repeated(stack))
	{
		ft_stkclear(&stack);
		write(1, "Error\n", 6);
		exit (0);
	}
	return (stack);
}

int	check_order(t_stack *stack)
{
	int		num;

	num = INT_MIN;
	while (stack)
	{
		if (stack->num >= num)
			num = stack->num;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}
