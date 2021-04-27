/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:15:33 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/27 19:17:07 by dbegara-         ###   ########.fr       */
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

#endif