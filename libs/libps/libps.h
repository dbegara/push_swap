/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:54:23 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/14 20:48:40 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include <stdlib.h>

typedef struct	s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_stknew(int content);
t_stack	*ft_stklast(t_stack *stk);
int		ft_stksize(t_stack *stk);
void	ft_stkswap(t_stack *stack);
void	ft_stkadd_front(t_stack **stk, t_stack *new);
void	ft_stkdel_front(t_stack **stack);
void	ft_stkadd_back(t_stack **stk, t_stack *new);
void	ft_stkdel_back(t_stack **stack);
void	ft_stkclear(t_stack **stk);
void	ft_stkpush(t_stack **dst, t_stack **src);
void	ft_stkrotate(t_stack **stack);
void	ft_stkrotate_rev(t_stack **stack);


#endif