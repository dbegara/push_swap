/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkrotate_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbegarabesco <davidbegarabesco@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:45:02 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/19 16:26:17 by davidbegara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkrotate_rev(t_stack **stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	tmp = (ft_stklast(*stack))->num;
	ft_stkdel_back(stack);
	ft_stkadd_front(stack, ft_stknew(tmp));
}
