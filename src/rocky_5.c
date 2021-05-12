/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocky_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 23:50:02 by davidbegara       #+#    #+#             */
/*   Updated: 2021/05/12 17:10:32 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	punch_numbers(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stksize(*stack_a) > 3)
	{
		ft_stkpush(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
}

t_neighbours	migthy_mick(t_stack *stack, int num)
{
	t_neighbours neighbours;
	t_stack	*tmp;
	int		*pose_tmp;

	neighbours.smlr = INT_MIN;
	neighbours.bigr = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num > neighbours.smlr && tmp->num < num)
			neighbours.smlr = tmp->num;
		if (tmp->num < neighbours.bigr && tmp->num > num)
			neighbours.bigr = tmp->num;
		tmp = tmp->next;
	}
	pose_tmp = get_num_pos(stack, 1, &neighbours.smlr, 1);
	neighbours.smlr_pose = *pose_tmp;
	free(pose_tmp);
	pose_tmp = get_num_pos(stack, 1, &neighbours.bigr, 1);
	neighbours.bigr_pose = *pose_tmp;
	free(pose_tmp);
	return (neighbours);
}

void	place_in_ring(t_stack **stack, t_neighbours neighbours, int stk_num)
{
	int	stk_size;

	stk_size = ft_stksize(*stack);
	if (neighbours.bigr_pose)
	{
		if ((neighbours.bigr_pose - 1) <= (stk_size / 2) || neighbours.bigr_pose == 1)
			frontal_sort(stack, neighbours.bigr_pose, stk_num);
		else
			reverse_sort(stack, neighbours.bigr_pose, stk_num);
	}
	else if (neighbours.smlr_pose)
	{
		if ((neighbours.smlr_pose - 1) <= (stk_size / 2) && neighbours.smlr_pose != 1)
			frontal_sort(stack, neighbours.smlr_pose - 1, stk_num);
		else
			reverse_sort(stack, neighbours.smlr_pose + 1, stk_num);
	}
}

void	knockout(t_stack **stack, int stk_size)
{
	int		smlr;
	int		i;
	int		j;
	t_stack	*tmp;

	smlr = INT_MAX;
	tmp = *stack;
	i = 1;
	j = 0;
	while (tmp)
	{
		if (smlr >= tmp->num)
		{
			smlr = tmp->num;
			j = i;
		}
		tmp = tmp->next;
		i++;
	}
	while((*stack)->num != smlr)
	{
		if ((j - 1) <= (stk_size / 2))
		{
			ft_stkrotate(stack);
			write(1, "ra\n", 3);
		}
		else
		{
			ft_stkrotate_rev(stack);
			write(1, "rra\n", 4);
		}
	}
}

void	rocky_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	punch_numbers(stack_a, stack_b);
	ironman_3(stack_a);
	while (*stack_b)
	{
		place_in_ring(stack_a, migthy_mick(*stack_a, (*stack_b)->num), 1);
		ft_stkpush(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	knockout(stack_a, ft_stksize(*stack_a));
}