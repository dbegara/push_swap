/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:59:32 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 15:47:30 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkadd_back(t_stack **stk, t_stack *new)
{
	t_stack	*last_stack;

	if (!stk || !new)
		return ;
	if (*stk == 0)
		*stk = new;
	else
	{
		last_stack = ft_stklast(*stk);
		last_stack->next = new;
	}
}
