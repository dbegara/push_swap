/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:53:12 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 18:03:07 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_cpybuffer(char *buffer, char *line)
{
	int		line_size;
	int		buffer_size;
	char	*new;

	if (line)
		line_size = ft_bufflen(line);
	else
		line_size = 0;
	buffer_size = ft_check_buff(buffer);
	new = malloc(line_size + buffer_size + 1);
	new[line_size + buffer_size] = 0;
	while (buffer_size > 0)
	{
		buffer_size--;
		new[line_size + buffer_size] = buffer[buffer_size];
	}
	while (line_size > 0)
	{
		line_size--;
		new[line_size] = line[line_size];
	}
	free(line);
	return (new);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstc;
	const char	*srcc;

	if (dst == 0 && src == 0)
		return (dst);
	dstc = (char *)dst;
	srcc = (const char *)src;
	while (n > 0)
	{
		*(dstc++) = *(srcc++);
		n--;
	}
	return (dst);
}

char	*ft_savepr(char *buffer)
{
	int		offset;
	int		size;
	char	*new;

	offset = ft_check_buff(buffer) + 1;
	size = ft_bufflen(buffer + offset);
	new = malloc(size + 1);
	new[size] = 0;
	while (size > 0)
	{
		size--;
		new[size] = buffer[size + offset];
	}
	return (new);
}

char	*ft_write_line(char **pr, char *buffer, char *line, int rt)
{
	if (ft_check_buff(buffer) == rt)
		line = ft_cpybuffer(buffer, line);
	if (ft_check_buff(buffer) < rt)
	{
		line = ft_cpybuffer(buffer, line);
		*pr = ft_savepr(buffer);
	}
	return (line);
}
