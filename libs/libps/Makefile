# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 19:18:48 by dbegara-          #+#    #+#              #
#    Updated: 2021/05/11 19:23:50 by dbegara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ		=		ft_stkadd_back.o ft_stkadd_front.o ft_stkclear.o ft_stkdel_back.o \
				ft_stkdel_front.o ft_stklast.o ft_stknew.o ft_stkpush.o ft_stkrotate.o \
				ft_stkrotate_rev.o ft_stksize.o ft_stkswap.o

LIB_NAME	=	libps.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

re: fclean all

fclean: clean
	@$(RM) libps.a

clean:
	@$(RM) *.o