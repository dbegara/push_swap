# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 17:56:32 by dbegara-          #+#    #+#              #
#    Updated: 2021/05/11 18:52:23 by dbegara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	=		gnl.o gnl_utils.o

CC		=		gcc
CFLAGS	=		-Wall -Werror -Wextra -D BUFFER_SIZE=32

GNL		=		libgnl.a

all: $(GNL)

$(GNL):	$(OBJS)
	ar rcs libgnl.a $(OBJS)

re: fclean all

fclean: clean
	@$(RM) libgnl.a

clean:
	@$(RM) *.o