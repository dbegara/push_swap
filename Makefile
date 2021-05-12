# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 18:54:58 by dbegara-          #+#    #+#              #
#    Updated: 2021/05/12 15:59:16 by dbegara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			=	src/
OBJ_DIR			=	obj/
BIN_DIR			=	bin
LIBFT_DIR		=	libs/libft
GNL_DIR			=	libs/gnl
LIBPS_DIR		=	libs/libps

COMMON_SRC		=	helper.c
COMMON_OBJ		:= 	$(addprefix $(OBJ_DIR), $(COMMON_SRC:.c=.o))
COMMON_SRC		:=	$(addprefix $(SRC_DIR), $(COMMON_SRC))

CHECKER_SRC		=	checker.c
CHECKER_OBJ		:= 	$(addprefix $(OBJ_DIR), $(CHECKER_SRC:.c=.o))
CHECKER_SRC		:=	$(addprefix $(SRC_DIR), $(CHECKER_SRC))

PUSH_SRC		=	algorithms_aux.c algorithms.c ironman_3.c rocky_5.c push_swap.c
PUSH_OBJ		:= 	$(addprefix $(OBJ_DIR), $(PUSH_SRC:.c=.o))
PUSH_SRC		:=	$(addprefix $(SRC_DIR), $(PUSH_SRC))



OBJ				=	$(CHECKER_OBJ) $(PUSH_OBJ) $(COMMON_OBJ)

CHECKER			=	$(BIN_DIR)/checker
PUSH			=	$(BIN_DIR)/push_swap
LIBFT			=	$(LIBFT_DIR)/libft.a
GNL				=	$(GNL_DIR)/libgnl.a
LIBPS			=	$(LIBPS_DIR)/libps.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

all: $(PUSH) $(CHECKER)

$(PUSH) : $(LIBFT) $(GNL) $(LIBPS) $(OBJ) $(BIN_DIR)
	gcc -L$(LIBFT_DIR) -lft -L$(LIBPS_DIR) -lps -L$(GNL_DIR) -lgnl -o $(PUSH) $(PUSH_OBJ) $(COMMON_OBJ)

$(CHECKER) : $(LIBFT) $(GNL) $(LIBPS) $(OBJ) $(BIN_DIR)
	gcc -L$(LIBFT_DIR) -lft -L$(LIBPS_DIR) -lps -L$(GNL_DIR) -lgnl -o $(CHECKER) $(CHECKER_OBJ) $(COMMON_OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJ_DIR)
	gcc -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

$(LIBPS):
	make -C $(LIBPS_DIR)

print:
	echo $(CHECKER_OBJ)

re: 
	make fclean 
	make all

fclean: clean
	@$(RM) -rv $(BIN_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)
	make fclean -C $(LIBPS_DIR)

clean:
	@$(RM) -rv $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(LIBPS_DIR)