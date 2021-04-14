/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:09:45 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/14 20:11:07 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkclear(t_stack **stk)
{
	t_stack		*element;
	t_stack		*tmp;

	element = *stk;
	while (element)
	{
		tmp = element->next;
		free(element);
		element = tmp;
	}
	*stk = NULL;
}