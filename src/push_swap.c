/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:54:24 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/10 19:43:15 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*bubble_sort(int *chunks, int size)
{
	int i;
	int j;
	int	tmp;

	i = 0;
	while (i < (size - 1))
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (chunks[j] > chunks[j + 1])
			{
				tmp = chunks[j];
				chunks[j] = chunks[j + 1];
				chunks[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (chunks);
}

int 	*order_stack(t_stack *stack)
{
	int	*chunks;
	int	stk_size;
	int	i;

	stk_size = ft_stksize(stack);
	chunks = malloc(sizeof(int) * ft_stksize(stack));
	i = 0;
	while(stack)
	{
		chunks[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (bubble_sort(chunks, stk_size));

}

int		ft_sqrt(int num)
{
	int i;

	i = 1;
	while (1)
	{
		if ((ft_abs(num - (i * i))) <
			(ft_abs(num - ((i + 1) * (i + 1)))))
			return (i);
		i++;
	}
}

int		cmp_chunk_num(int *chunk, int chunk_size, int num)
{
	while (chunk_size)
	{
		chunk_size--;
		if (chunk[chunk_size] == num)
			return (1);
	}
	return (0);
}

int		*get_num_pos(t_stack *stack_a, int chunk_size, int *chunk, int size)
{
	int	i;
	int	j;
	int	*poses;

	if (!chunk_size)
		return (NULL);
	poses = malloc(4 * chunk_size);
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

int		num_to_push(int stk_size, int hold_first, int hold_second)
{
	int	first_diff;
	int	second_diff;

	first_diff = ft_abs((stk_size / 2) - (hold_first));
	second_diff = ft_abs((stk_size / 2) - (hold_second));

	if (first_diff > second_diff || first_diff < 2)
		return (hold_first);
	return (hold_second);
}

void	push_number(t_stack **stack_a, t_stack **stack_b, int *poses, int chunk_size)
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

void	push_chunk(t_stack **stack_a, t_stack **stack_b, int chunk_size, int *chunk)
{
	int	*poses;
	int	size;

	size = chunk_size;
	poses = get_num_pos(*stack_a, chunk_size, chunk, size);
	while (chunk_size)
	{
		push_number(stack_a, stack_b, poses, chunk_size);
		free(poses);
		poses = get_num_pos(*stack_a, chunk_size - 1, chunk, size);
		chunk_size--;
	}
}

void	new_order_stuff(t_stack **stack_a, t_stack **stack_b, int *chunks)
{
	int	stk_size;
	int	chunk_size;
	int	actual_chunk;

	stk_size = ft_stksize(*stack_a);
	chunk_size = (stk_size) / (ft_sqrt(stk_size) / 2);
	actual_chunk = 0;
	while (1)
	{
		if ((stk_size - (actual_chunk * chunk_size)) <= chunk_size)
		{
			stk_size = stk_size - (chunk_size * actual_chunk);
			push_chunk(stack_a, stack_b, stk_size, chunks + (chunk_size * actual_chunk));
			break;
		}
		push_chunk(stack_a, stack_b, chunk_size, chunks + (chunk_size * actual_chunk));
		actual_chunk++;
	}

}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*chunks;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	chunks = order_stack(stack_a);
	
	if (ft_stksize(stack_a) == 3 && !check_order(stack_a))
		ironman_3(&stack_a, &stack_b);
	else if (ft_stksize(stack_a) > 1 && !check_order(stack_a))
	{
		new_order_stuff(&stack_a, &stack_b, chunks);
		super_sort(&stack_a, &stack_b);
	}
	free(chunks);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	//system("leaks push_swap");
	
	return (0);
}
