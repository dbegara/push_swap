/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:47:18 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 18:15:44 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_chunk_num(int *chunk, int chunk_size, int num)
{
	while (chunk_size)
	{
		chunk_size--;
		if (chunk[chunk_size] == num)
			return (1);
	}
	return (0);
}

int	*get_num_pos(t_stack *stack_a, int chunk_size, int *chunk, int size)
{
	int	i;
	int	j;
	int	*poses;

	if (!chunk_size)
		return (NULL);
	poses = ft_calloc(chunk_size, sizeof(int));
	i = 1;
	j = 0;
	while (stack_a)
	{
		if (cmp_chunk_num(chunk, size, stack_a->num))
		{
			poses[j] = i;
			j++;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (poses);
}

int	num_to_push(int stk_size, int hold_first, int hold_second)
{
	int	first_diff;
	int	second_diff;

	first_diff = ft_abs((stk_size / 2) / (stk_size - hold_first + 1));
	second_diff = ft_abs((stk_size / 2) / (stk_size - hold_second + 1));
	if (first_diff > second_diff || first_diff < 2)
		return (hold_first);
	return (hold_second);
}

void	push_number(t_stack **stack_a, t_stack **stack_b,
	int *poses, int chunk_size)
{
	int		hold_first;
	int		hold_second;

	hold_first = ft_stksize(*stack_a);
	hold_second = 1;
	while (chunk_size)
	{
		chunk_size--;
		if (poses[chunk_size] < hold_first)
			hold_first = poses[chunk_size];
		if (poses[chunk_size] > hold_second)
			hold_second = poses[chunk_size];
	}
	hold_first = num_to_push(ft_stksize(*stack_a), hold_first, hold_second);
	move_small(stack_a, stack_b, ft_stksize(*stack_a), hold_first);
}

void	push_chunk(t_stack **stack_a, t_stack **stack_b,
	int chunk_size, int *chunk)
{
	int	*poses;
	int	size;

	size = chunk_size;
	poses = get_num_pos(*stack_a, chunk_size, chunk, size);
	while (chunk_size)
	{
		push_number(stack_a, stack_b, poses, chunk_size);
		free(poses);
		poses = get_num_pos(*stack_a, chunk_size, chunk, size);
		chunk_size--;
	}
}
