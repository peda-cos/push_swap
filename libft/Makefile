# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 13:27:12 by peda-cos          #+#    #+#              #
#    Updated: 2024/12/28 20:32:05 by peda-cos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = \
	ft_atoi.c ft_copycat.c ft_itoa.c ft_lstdel.c ft_memory.c ft_puthex_fd.c \
	ft_putptr_fd.c ft_split.c ft_strmod.c get_next_line.c ft_calloc.c \
	ft_istype.c ft_lstadd.c ft_lstutil.c ft_printf.c ft_putnbr_fd.c \
	ft_puts_fd.c ft_string.c ft_strutil.c ft_isspace.c ft_minmax.c \
	ft_putendl_fd.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
