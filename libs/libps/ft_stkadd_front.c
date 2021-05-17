/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:12:34 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 15:47:38 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkadd_front(t_stack **stk, t_stack *new)
{
	if (!stk)
		return ;
	if (!*stk)
	{
		*stk = new;
		return ;
	}
	new->next = *stk;
	*stk = new;
}
