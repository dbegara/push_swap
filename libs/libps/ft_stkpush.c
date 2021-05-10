/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:30:30 by dbegara-          #+#    #+#             */
/*   Updated: 2021/04/14 20:33:31 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_stkpush(t_stack **dst, t_stack **src)
{
	int		tmp;

	if (!src || !dst)
		return ;
	if (!*src)
		return ;
	tmp = (*src)->num;
	ft_stkdel_front(src);
	ft_stkadd_front(dst, ft_stknew(tmp));
}