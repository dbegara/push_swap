/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:28:41 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 15:48:05 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkdel_front(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}
