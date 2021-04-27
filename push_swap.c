/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:54:24 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/27 19:55:37 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		ft_abs(int num)
{
	if (num < 0)
	 	num = num * -1;
	return (num);
}

void	move_small(t_stack **stack_a, t_stack **stack_b, int stk_size, int num_pos)
{
	if (num_pos <= (stk_size / 2))
		frontal_sort(stack_a, num_pos);
	else
		reverse_sort(stack_a, num_pos);
	if (stk_size > 1)
	{
		ft_stkpush(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
	
}

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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	super_sort(&stack_a, &stack_b);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	//system("leaks checker");
	return (0);
}
