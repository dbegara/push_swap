/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ironman_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:59:24 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/28 14:14:09 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ark_pos(t_stack *stack_a, int num)
{
	int i;

	i = 0;
	while (stack_a)
	{
		if (num < stack_a->num)
			i++;
		stack_a = stack_a->next;
	}
	return(i);
}

void	ironman_3(t_stack **stack_a, t_stack **stack_b)
{
	if (check_order(*stack_a))
		return ;
	if ((ark_pos(*stack_a, (*stack_a)->num)) == 0)
	{
		ft_stkrotate(stack_a);
		write(1, "ra\n", 3);
	}
	if ((ark_pos(*stack_a, (*stack_a)->num)) == 1)
	{
		if ((ark_pos(*stack_a, (*stack_a)->next->num)) == 0)
		{
			ft_stkrotate_rev(stack_a);
			write(1, "rra\n", 4);
			return ;
		}
		ft_stkswap(*stack_a);
		write(1, "sa\n", 3);
		ironman_3(stack_a, stack_b);
	}
}
