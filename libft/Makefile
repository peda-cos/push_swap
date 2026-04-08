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

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atol.c ft_split.c ft_putstr_fd.c ft_putendl_fd.c \
       ft_strlen.c ft_strdup.c ft_substr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Compiled: $(NAME)"

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@rm -f $(OBJS)
	@echo "Cleaned: $(OBJS)"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned: $(NAME)"

re: fclean all

.PHONY: all clean fclean re
