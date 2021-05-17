/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:08:55 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 18:12:05 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_bufflen(char *buffer)
{
	int	length;

	length = 0;
	while (buffer[length] != 0)
		length++;
	return (length);
}

int	ft_check_buff(char *buffer)
{
	int	length;

	length = 0;
	while (buffer[length] != '\n' && buffer[length] != 0)
		length++;
	return (length);
}

int	return_func(int rt, char **line)
{
	if (rt == 0)
	{
		*line = ft_cpybuffer("", *line);
		return (0);
	}
	if (rt < BUFFER_SIZE && rt > 0)
		return (0);
	return (-1);
}

int	print_buffer(char **pr, char *buffer, int fd, char **line)
{
	ft_memcpy(buffer, *pr, ft_bufflen(*pr) + 1);
	free(*pr);
	*pr = NULL;
	*line = ft_write_line(&pr[fd], buffer, *line, ft_bufflen(buffer));
	if (pr[fd])
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*pr[FD_SIZE];
	int			rt;
	char		buffer[BUFFER_SIZE + 1];

	if (line == NULL)
		return (-1);
	*line = NULL;
	if (pr[fd])
	{
		if (print_buffer(&pr[fd], buffer, fd, line) == 1)
			return (1);
	}
	rt = read(fd, buffer, BUFFER_SIZE);
	while (rt > 0)
	{
		buffer[rt] = 0;
		*line = ft_write_line(&pr[fd], buffer, *line, rt);
		if (ft_check_buff(buffer) < rt)
			return (1);
		rt = read(fd, buffer, BUFFER_SIZE);
	}
	return (return_func(rt, line));
}
