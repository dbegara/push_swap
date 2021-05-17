/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:54:24 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 18:17:57 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int num)
{
	int	i;

	i = 1;
	while (1)
	{
		if ((ft_abs(num - (i * i)))
			< (ft_abs(num - ((i + 1) * (i + 1)))))
			return (i);
		i++;
	}
}

void	new_order_stuff(t_stack **stack_a, t_stack **stack_b)
{
	int	*chunks;
	int	stk_size;
	int	chunk_size;
	int	actual_chunk;

	chunks = order_stack(*stack_a);
	stk_size = ft_stksize(*stack_a);
	chunk_size = (stk_size) / (ft_sqrt(stk_size) / 2);
	actual_chunk = 0;
	while (1)
	{
		if ((stk_size - (actual_chunk * chunk_size)) <= chunk_size)
		{
			stk_size = stk_size - (chunk_size * actual_chunk);
			push_chunk(stack_a, stack_b, stk_size, chunks
				+ (chunk_size * actual_chunk));
			break ;
		}
		push_chunk(stack_a, stack_b, chunk_size, chunks
			+ (chunk_size * actual_chunk));
		actual_chunk++;
	}
	super_sort(stack_a, stack_b);
	free(chunks);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stk_size;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	stk_size = ft_stksize(stack_a);
	if (stk_size == 3 && !check_order(stack_a))
		ironman_3(&stack_a);
	else if (((stk_size) / (ft_sqrt(stk_size) / 2) == stk_size)
		&& !check_order(stack_a))
		rocky_5(&stack_a, &stack_b);
	else if (stk_size > 1 && !check_order(stack_a))
		new_order_stuff(&stack_a, &stack_b);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (0);
}
