/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:15:33 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/28 13:59:44 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libps/libps.h"
# include "libft/libft.h"
# include <limits.h>

char	*ft_strtok_ps(char *str, char delim);
int		ft_atoi(char *num);
void	fill_stack_loop(int i, int argc, t_stack **stack, char **argv);
t_stack	*fill_stack(int argc, char **argv);
int		check_order(t_stack *stack);
int		ft_abs(int num);
int		smlr_elem_pos(t_stack *stk, int *exclude);
void	frontal_sort(t_stack **stack_a, int num_pos);
void	reverse_sort(t_stack **stack_a, int num_pos);
void	move_small(t_stack **stack_a, t_stack **stack_b, int stk_size, int num_pos);
void	super_sort(t_stack **stack_a, t_stack **stack_b);
void	ironman_3(t_stack **stack_a, t_stack **stack_b);

#endif