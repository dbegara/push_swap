/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:15:33 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/19 16:21:37 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/libps/libps.h"
# include "../libs/gnl/gnl.h"
# include <limits.h>

typedef struct s_neighbours {
	int	bigr;
	int	bigr_pose;
	int	smlr;
	int	smlr_pose;
}				t_neighbours;

typedef struct s_num
{
	int	num;
	int	pos;
}				t_num;

char			*ft_strtok_ps(char *str, char delim);
int				ft_atoi(char *num);
void			fill_stack_loop(int i, t_stack **stack, char **argv);
t_stack			*fill_stack(int argc, char **argv);
int				check_order(t_stack *stack);
int				ft_abs(int num);
int				bigr_elem_pos(t_stack *stk, int *exclude);
void			frontal_sort(t_stack **stack_a, int num_pos, int stack);
void			reverse_sort(t_stack **stack_a, int num_pos, int stack);
void			move_small(t_stack **stack_a, t_stack **stack_b,
					int stk_size, int num_pos);
void			move_small_b(t_stack **stack_b, t_stack **stack_a,
					int stk_size, int num_pos);
void			super_sort(t_stack **stack_a, t_stack **stack_b);
void			ironman_3(t_stack **stack_a);
int				*get_num_pos(t_stack *stack_a, int chunk_size,
					int *chunk, int size);
void			place_in_ring(t_stack **stack,
					t_neighbours neighbours, int stk_num);
t_neighbours	migthy_mick(t_stack *stack, int num);
void			rocky_5(t_stack **stack_a, t_stack **stack_b);
void			push_chunk(t_stack **stack_a, t_stack **stack_b,
					int chunk_size, int *chunk);
int				*order_stack(t_stack *stack);
int				check_repeated(t_stack *stack_a);
void			error_exit(void);

#endif