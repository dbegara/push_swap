/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:51:49 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 15:51:12 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkswap(t_stack *stack)
{
	int	tmp;

	if (ft_stksize(stack) < 2)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	return ;
}
