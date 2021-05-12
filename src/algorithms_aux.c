/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:33:47 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/12 20:01:55 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigr_elem_pos(t_stack *stk, int *exclude)
{
	int	bigr;
	int	i;
	int	pos;

	bigr = INT_MIN;
	i = 0;
	while (stk)
	{
		i++;
		if (stk->num > bigr && *exclude != stk->num)
		{
			bigr = stk->num;
			pos = i;
		}
		stk = stk->next;
	}
	*exclude = bigr;
	return (pos);
}

void	frontal_sort(t_stack **stack_a, int num_pos, int stack)
{
	while (--num_pos)
	{
		ft_stkrotate(stack_a);
		if (stack == 1)
			write(1, "ra\n", 3);
		else if (stack == 2)
			write(1, "rb\n", 3);
	}
}

void	reverse_sort(t_stack **stack_a, int num_pos, int stack)
{
	int		stk_size;

	stk_size = ft_stksize(*stack_a);
	while (num_pos++ <= stk_size)
	{
		ft_stkrotate_rev(stack_a);
		if (stack == 1)
			write(1, "rra\n", 4);
		else if (stack == 2)
			write(1, "rrb\n", 4);
	}
}

void	move_small(t_stack **stack_a, t_stack **stack_b,
		int stk_size, int num_pos)
{
	if (num_pos <= (stk_size / 2) || num_pos == 1)
		frontal_sort(stack_a, num_pos, 1);
	else
		reverse_sort(stack_a, num_pos, 1);
	ft_stkpush(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	move_small_b(t_stack **stack_b, t_stack **stack_a,
		int stk_size, int num_pos)
{
	if (num_pos <= (stk_size / 2) || num_pos == 1)
		frontal_sort(stack_b, num_pos, 2);
	else
		reverse_sort(stack_b, num_pos, 2);
	if (check_order(*stack_b) && stk_size > 1)
		return ;
	ft_stkpush(stack_a, stack_b);
	write(1, "pa\n", 3);
}
