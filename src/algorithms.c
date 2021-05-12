/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:32:22 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/12 13:43:10 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

void	magic_move_aux(t_stack **stack_a, t_stack **stack_b,
	t_neighbours num_pos, int *exclude)
{
	int		stk_size;
	int		smlr_diff;
	int		bigr_diff;

	stk_size = ft_stksize(*stack_b);
	smlr_diff = ft_abs((stk_size / 2) / (stk_size - num_pos.bigr + 1));
	bigr_diff = ft_abs((stk_size / 2) / (stk_size - num_pos.smlr + 1));
	if (bigr_diff > (smlr_diff + 1)
		&& (bigr_diff - smlr_diff) < (stk_size / 2))
	{
		move_small_b(stack_b, stack_a, stk_size, num_pos.smlr);
		move_small_b(stack_b, stack_a, stk_size,
			bigr_elem_pos(*stack_b, exclude));
		ft_stkswap(*stack_a);
		write(1, "sa\n", 3);
	}
	else
		move_small_b(stack_b, stack_a, stk_size, num_pos.bigr);
}

void	magic_move(t_stack **stack_a, t_stack **stack_b, int stk_size)
{
	t_neighbours num_pos;
	int		*exclude;

	exclude = malloc(sizeof(int));
	*exclude = INT_MIN;
	num_pos.bigr = bigr_elem_pos(*stack_b, exclude);
	num_pos.smlr = bigr_elem_pos(*stack_b, exclude);
	*exclude = INT_MIN;
	if (num_pos.bigr == 2 && num_pos.smlr == 1)
	{
		ft_stkswap(*stack_b);
		write(1, "sb\n", 3);
		free(exclude);
		return ;
	}
	magic_move_aux(stack_a, stack_b, num_pos, exclude);
	free(exclude);
}

void	super_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		stk_size;

	stk_size = ft_stksize(*stack_b);
	while (stk_size)
	{	
		magic_move(stack_a, stack_b, stk_size);
		stk_size = ft_stksize(*stack_b);
	}
}
