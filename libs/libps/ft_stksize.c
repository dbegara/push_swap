/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stksize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:02:28 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 15:50:57 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ft_stksize(t_stack *stk)
{
	int	counter;

	counter = 0;
	while (stk)
	{
		stk = stk->next;
		counter++;
	}
	return (counter);
}
