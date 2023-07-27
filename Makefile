# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 01:43:42 by cmateos-          #+#    #+#              #
#    Updated: 2023/07/17 19:29:12 by cmateos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# COLORS #
COLOR_RESET = \x1b[0m
COLOR_RED = \x1b[1;31m
COLOR_GREEN = \x1b[1;32m
COLOR_YELLOW = \x1b[1;33m
COLOR_BLUE = \x1b[1;34m
COLOR_MAGENTA = \x1b[35m
COLOR_CYAN = \x1b[1;36m
BLANCO_T = \x1b[37m
BLANCO_F = \x1b[47m
MAGENTA = \033[0;95m
BROWN =	\033[38;2;184;143;29m

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm -f
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
SRC = ./src/main.c ./src/ft_error.c ./src/ft_fill_stack.c ./src/ft_check_arg.c ./src/push_swap.c ./src/moves.c ./src/utils_stack.c ./src/utils_stack2.c \
		./src/ft_index.c ./src/ft_atoi_pushswap.c
OBJ = $(SRC:.c=.o)
INCLUDE = push_swap.h
#MAIN = ./src/main.c
MAIN_OBJ = $(MAIN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

$(LIBFT):
	@echo "${COLOR_BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(COLOR_YELLOW)$<"
	make -C $(LIBFT_DIR)
	@echo "$(COLOR_GREEN) Created! :3 $(COLOR_RESET)"


%.o: %.c
	@echo "${COLOR_BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(COLOR_CYAN)$< $(COLOR_RESET)"
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(COLOR_GREEN) Created! :3 $(COLOR_RESET)"

clean:
	rm -f $(OBJ) $(LIBFT)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

	@echo "$(COLOR_BLUE) Cleaned all! $(COLOR_RESET)"

normi:
	norminette

#main: $(NAME) $(MAIN_OBJ)
#	gcc $(NAME) $(MAIN_OBJ) -o push_swap

#run_main: $(NAME) $(MAIN_OBJ)
#	gcc $(NAME) $(MAIN_OBJ) -o push_swap && ./src/push_swap

re: fclean all

.PHONY: all, clean, fclean, re
