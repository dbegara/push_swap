/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:04:48 by dbegara-          #+#    #+#             */
/*   Updated: 2021/05/06 18:53:19 by dbegara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_SIZE 4096
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
int		ft_check_buff(char *buffer);
char	*ft_cpybuffer(char *buffer, char *line);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*ft_savepr(char *buffer);
char	*ft_write_line(char **pr, char *buffer, char *line, int rt);
int		get_next_line(int fd, char **line);

#endif
