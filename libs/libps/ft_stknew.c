/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stknew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:56:30 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 15:49:59 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libps.h"

t_stack	*ft_stknew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->num = content;
	new_node->next = 0;
	return (new_node);
}
