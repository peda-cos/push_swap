NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = main.c push_operations.c rotate_operations.c reverse_rotate_operations.c
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
