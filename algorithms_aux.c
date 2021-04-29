/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:33:47 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/28 13:47:52 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_abs(int num)
{
	if (num < 0)
	 	num = num * -1;
	return (num);
}

int		smlr_elem_pos(t_stack *stk, int *exclude)
{
	int	smlr;
	int	i;
	int	pos;

	smlr = INT_MAX;
	i = 0;
	while (stk)
	{
		i++;
		if (stk->num < smlr && *exclude != stk->num)
		{
			smlr = stk->num;
			pos = i;
		}
		stk = stk->next;
	}
	*exclude = smlr;
	return (pos);
}

void	frontal_sort(t_stack **stack_a, int num_pos)
{
	while (--num_pos)
	{
		ft_stkrotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	reverse_sort(t_stack **stack_a, int num_pos)
{
	int		stk_size;

	stk_size = ft_stksize(*stack_a);
	while (num_pos++ <= stk_size)
	{
		ft_stkrotate_rev(stack_a);
		write(1, "rra\n", 4);
	}
}

void	move_small(t_stack **stack_a, t_stack **stack_b, int stk_size, int num_pos)
{
	if (num_pos <= (stk_size / 2))
		frontal_sort(stack_a, num_pos);
	else
		reverse_sort(stack_a, num_pos);
	if (check_order(*stack_a))
		return ;
	if (stk_size > 1)
	{
		ft_stkpush(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
}
