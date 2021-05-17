/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:48:02 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 18:16:31 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int *chunks, int size)
{
	int	i;
	int	j;
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

int	*order_stack(t_stack *stack)
{
	int	*chunks;
	int	stk_size;
	int	i;

	stk_size = ft_stksize(stack);
	chunks = malloc(sizeof(int) * ft_stksize(stack));
	i = 0;
	while (stack)
	{
		chunks[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (bubble_sort(chunks, stk_size));
}
