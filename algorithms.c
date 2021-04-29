/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:32:22 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/28 13:59:35 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	magic_move(t_stack **stack_a, t_stack **stack_b, int stk_size)
{
	int		smlr_num_pos;
	int		bigr_num_pos;
	int		smlr_diff;
	int		bigr_diff;
	int		*exclude;

	exclude = malloc(sizeof(int));
	*exclude = INT_MIN;
	smlr_num_pos = smlr_elem_pos(*stack_a, exclude);
	bigr_num_pos = smlr_elem_pos(*stack_a, exclude);
	if (smlr_num_pos == 2 && bigr_num_pos == 1)
	{
		ft_stkswap(*stack_a);
		write(1, "sa\n", 3);
		free(exclude);
		return ;
	}
	smlr_diff = ft_abs((stk_size / 2) / (stk_size - smlr_num_pos + 1));
	bigr_diff = ft_abs((stk_size / 2) / (stk_size - bigr_num_pos + 1));
	if (bigr_diff > (smlr_diff + 1) &&
		(bigr_diff - smlr_diff) < (stk_size / 2))
	{
		move_small(stack_a, stack_b, stk_size, bigr_num_pos);
		move_small(stack_a, stack_b, stk_size, smlr_elem_pos(*stack_a, exclude));
		ft_stkswap(*stack_b);
		write(1, "sb\n", 3);
	}
	else
		move_small(stack_a, stack_b, stk_size, smlr_num_pos);
	free(exclude);
}

void	super_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		stk_size;
	int		smlr_num_pos;
	int		bigr_num_pos;

	stk_size = ft_stksize(*stack_a);
	if (stk_size == 3)
	{
		ironman_3(stack_a, stack_b);
		return ;
	}
	while (stk_size > 1)
	{
		if (check_order(*stack_a))
			break ;
		
		magic_move(stack_a, stack_b, stk_size);
		stk_size = ft_stksize(*stack_a);
	}
	stk_size = ft_stksize(*stack_b);
	while (stk_size--)
	{
		ft_stkpush(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}