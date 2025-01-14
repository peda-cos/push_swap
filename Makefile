# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peda-cos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 19:39:12 by peda-cos          #+#    #+#              #
#    Updated: 2025/01/14 19:39:13 by peda-cos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = main.c push_operations.c swap_operations.c rotate_operations.c reverse_rotate_operations.c sorting_algorithms.c sorting_helpers.c sorting_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "Push_swap build complete."

$(LIBFT):
	@make -C $(LIBFT_DIR) all
	@echo "Libft build complete."

%.o: %.c push_swap.h libft/libft.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "Clean complete."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "Fclean complete."

re: fclean all

.PHONY: all clean fclean re
