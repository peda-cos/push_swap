# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 00:00:00 by peda-cos          #+#    #+#              #
#    Updated: 2026/04/08 00:00:00 by peda-cos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft

SRCS = src/main.c src/stack_utils.c src/operations_swap.c \
       src/operations_push.c src/operations_rotate.c src/operations_rev.c \
       src/parsing.c src/parsing_utils.c src/sort_utils.c src/sort_small.c \
       src/sort_turk.c src/sort_turk_utils.c src/sort_execute.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/checker_bonus.c bonus/checker_utils_bonus.c \
             src/stack_utils.c src/operations_swap.c src/operations_push.c \
             src/operations_rotate.c src/operations_rev.c src/parsing.c \
             src/parsing_utils.c src/sort_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "Compiled: $(NAME)"

src/%.o: src/%.c include/push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)
	@touch .bonus
	@echo "Compiled: $(BONUS_NAME)"

bonus/%.o: bonus/%.c bonus/checker_bonus.h include/push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS) $(BONUS_OBJS) .bonus
	@echo "Cleaned objects"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "Cleaned: $(NAME) $(BONUS_NAME)"

re: fclean all

.PHONY: all clean fclean re bonus
