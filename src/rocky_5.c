/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocky_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 23:50:02 by davidbegara       #+#    #+#             */
/*   Updated: 2021/05/12 00:21:41 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	punch_numbers(t_stack **stack_a, t_stack **stack_b)
{
	ft_stkpush(stack_b, stack_a);
	write(1, "pb\n", 3);
	ft_stkpush(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	migthy_mick(t_stack **stack, int num)
{

	// Tiene que rotar la pila para encontrar la posición correcta en la que meter el número.
	// La intención es que sea reutilizable para poder implementarla en la version final de Mazinger Infinity.

	int		smlr;
	int		bigr;
	t_stack	*tmp;

	smlr = INT_MIN;
	bigr = INT_MAX;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->num > smlr && tmp->num < num)
			smlr = tmp->num;
		if (tmp->num < bigr && tmp->num > num)
			bigr = tmp->num;
		tmp = tmp->next;
	}

	// Aquí queda mucha mierda por hacer, de momento tenemos los números entre los que se encuentra.
	// Hay que calcular como interesa rotar la pila para cuadrarlo con el menor número de movimientos posibles.
}

void	rocky_5(t_stack **stack_a, t_stack **stack_b)
{
	punch_numbers(stack_a, stack_b);
	ironman_3(stack_a);

}