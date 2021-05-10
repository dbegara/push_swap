# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbegara- <dbegara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 18:54:58 by dbegara-          #+#    #+#              #
#    Updated: 2021/05/10 19:28:26 by dbegara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

CHECKER_SRC = $(SRC_DIR)/checker.c $(SRC_DIR)/helper.c
PUSH_SRC = $(SRC_DIR)/algorithms_aux.c $(SRC_DIR)/algorithms.c $(SRC_DIR)/ironman_3.c $(SRC_DIR)/push_swap.c

CHECKER_OBJ = $(OBJ_DIR)/checker.o $(OBJ_DIR)/helper.o
PUSH_OBJ = $(OBJ_DIR)/algorithms_aux.o $(OBJ_DIR)/algorithms.o $(OBJ_DIR)/ironman_3.o $(OBJ_DIR)/push_swap.o $(OBJ_DIR)/helper.o

OBJ = $(OBJ_DIR)/algorithms_aux.o $(OBJ_DIR)/algorithms.o $(OBJ_DIR)/ironman_3.o $(OBJ_DIR)/push_swap.o $(OBJ_DIR)/helper.o $(OBJ_DIR)/checker.o

NAME_CHECKER = $(BIN_DIR)/checker
NAME_PUSH = $(BIN_DIR)/push_swap

all: libs | $(NAME_PUSH)

$(NAME_PUSH) : $(NAME_CHECKER)
	gcc -Llibs/libft -lft -Llibs/libps -lps -Llibs/gnl -lgnl -o $(NAME_PUSH) $(PUSH_OBJ)

$(NAME_CHECKER) : $(OBJ) | $(BIN_DIR)
	gcc -Llibs/libft -lft -Llibs/libps -lps -Llibs/gnl -lgnl -o $(NAME_CHECKER) $(CHECKER_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

re: fclean all

fclean: clean
	@$(RM) -rv $(BIN_DIR)

clean:
	@$(RM) -rv $(OBJ_DIR)