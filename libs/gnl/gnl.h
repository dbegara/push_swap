/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:04:48 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/17 15:33:42 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# define FD_SIZE 4096

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_bufflen(char *buffer);
int		ft_check_buff(char *buffer);
char	*ft_cpybuffer(char *buffer, char *line);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_savepr(char *buffer);
char	*ft_write_line(char **pr, char *buffer, char *line, int rt);
int		get_next_line(int fd, char **line);

#endif
