/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkrotate_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:45:02 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 15:50:16 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkrotate_rev(t_stack **stack)
{
	int	tmp;

	tmp = (ft_stklast(*stack))->num;
	ft_stkdel_back(stack);
	ft_stkadd_front(stack, ft_stknew(tmp));
}
