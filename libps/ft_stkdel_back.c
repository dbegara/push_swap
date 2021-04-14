/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:59:06 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/14 20:08:36 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkdel_back(t_stack **stack)
{
	t_stack		*tmp;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	tmp = *stack;
	while(tmp->next->next)
	{
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;
}