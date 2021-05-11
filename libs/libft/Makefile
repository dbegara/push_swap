# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:06:45 by dbegara-          #+#    #+#              #
#    Updated: 2021/05/11 19:22:46 by dbegara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS		=	ft_isdigit.o ft_memcmp.o ft_strlen.o

LIB_NAME	=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rcs libft.a $(OBJS)

re: fclean all

fclean: clean
	@$(RM) libft.a

clean:
	@$(RM) *.o
