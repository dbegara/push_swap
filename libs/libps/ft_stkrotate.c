/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:37:29 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/14 20:42:30 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkrotate(t_stack **stack)
{
	int		tmp;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	tmp = (*stack)->num;
	ft_stkdel_front(stack);
	ft_stkadd_back(stack, ft_stknew(tmp));
}