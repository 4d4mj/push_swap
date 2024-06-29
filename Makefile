# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 16:06:12 by ajabado           #+#    #+#              #
#    Updated: 2024/06/29 16:06:12 by ajabado          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

NAME = push_swap
CHECKER = checker_OS
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./src/libft
LIBFT = $(LIBFT_DIR)/libft.a

# push_swap sources
SRCS = $(wildcard ./src/*/*.c) \
				push_swap.c
OBJS = $(SRCS:.c=.o)

# checker sources
CHECKER_SRCS = $(wildcard ./src/*/*.c) \
						checker.c
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

# Compilation rules
all: $(LIBFT) $(NAME) $(CHECKER)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${YELLOW}Executable $(NAME) created.${NC}"

$(CHECKER): $(CHECKER_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${YELLOW}Executable $(CHECKER) created.${NC}"

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@echo "${CYAN}Compiling $<...${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS) $(CHECKER_OBJS)
	@echo "${GREEN}Object files cleaned.${NC}"

fclean:
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(OBJS) $(CHECKER_OBJS)
	@rm -f $() $(NAME) $(CHECKER)
	@echo "${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re
