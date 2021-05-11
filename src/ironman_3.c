/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ironman_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:59:24 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/11 23:12:50 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ark_pos(t_stack *stack_a, int num)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (num < stack_a->num)
			i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	get_combi(t_stack *stack_a)
{
	int		first;
	int		second;
	int		third;

	first = ark_pos(stack_a, stack_a->num);
	second = ark_pos(stack_a, stack_a->next->num);
	third = ark_pos(stack_a, stack_a->next->next->num);
	if (first == 1 && second == 2 && third == 0)
		return (1);
	if (first == 0 && second == 1 && third == 2)
		return (2);
	if (first == 0 && second == 2 && third == 1)
		return (3);
	if (first == 2 && second == 0 && third == 1)
		return (4);
	return (5);
}

void	ironman_3(t_stack **stack_a)
{
	int combi;

	if (check_order(*stack_a))
		return ;
	combi = get_combi(*stack_a);
	if (combi < 3 || combi == 4)
	{
		ft_stkswap(*stack_a);
		write(1, "sa\n", 3);
	}
	if (combi == 2 || combi == 5)
	{
		ft_stkrotate_rev(stack_a);
		write(1, "rra\n", 4);
	}
	if (combi == 3 || combi == 4)
	{
		ft_stkrotate(stack_a);
		write(1, "ra\n", 3);
	}
}
