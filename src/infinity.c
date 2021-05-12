/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:05:30 by davidbegara       #+#    #+#             */
/*   Updated: 2021/05/13 00:55:57 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Aquí hay que meter la nueva implementación para calcular:
	// 1º - Si está en la primera mitad ¿?
		// 2º - Si existe un número más pequeño en B
			// 3º - Si existe cuantos 'rb' hacen falta para ponerlo en el top.
			// 4º - Número de 'ra' necesarios para subir el número en A.
			// 5º - Ejecutar 'rr', el número de veces de 'ra' si 'ra' es más pequeño que 'rb', o viceversa.

typedef struct	s_bmove {
	int	ra_num;
	int	rb_num;
}				t_bmove;

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_bmove bmove, int num)
{
	int	tmp;

	tmp = bmove.rb_num;
	while (tmp)
	{
		ft_stkrotate(stack_a);
		ft_stkrotate(stack_b);
		write(1, "rr\n", 3);
		tmp--;
	}
	while (bmove.ra_num)
	{
		ft_stkrotate(stack_a);
		write(1, "ra\n", 3);
		bmove.ra_num--;
	}
	move_small(stack_a, stack_b, ft_stksize(*stack_a), num);
	while (bmove.rb_num)
	{
		ft_stkrotate_rev(stack_b);
		write(1, "rrb\n", 4);
		bmove.rb_num--;
	}
}

void	move_to_b(t_stack **stack_a, t_stack **stack_b, int num)
{
	int				stk_size;
	int				*pose_tmp;
	t_bmove			bmove;
	t_neighbours	nb;

	stk_size = ft_stksize(*stack_a); 
	pose_tmp = get_num_pos(*stack_a, 1, &num, 1);
	bmove.ra_num = *pose_tmp - 1;
	free(pose_tmp);
	bmove.rb_num = 0;
	if (bmove.ra_num < stk_size / 2)
	{
		nb = migthy_mick(*stack_b, num);
		if (nb.smlr_pose)
			bmove.rb_num = nb.smlr_pose - 1;
		if (bmove.rb_num && bmove.rb_num < bmove.ra_num)
		{
			bmove.ra_num -= bmove.rb_num;
			rotate_both(stack_a, stack_b, bmove, num);
			return ;
		}
	}
	move_small(stack_a, stack_b, stk_size, num);
}