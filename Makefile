# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 13:33:44 by hadufer           #+#    #+#              #
#    Updated: 2021/11/16 10:37:30 by hadufer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SRCS = debug.c \
list_util.c \
logic.c \
logic_3.c \
logic_3_utils.c \
logic_utils.c \
operation.c \
operation_list.c \
parsing.c \
parsing_2.c \
pre_sort.c \
unit_util.c \
unit_util_2.c \
push_swap_main_utils.c \
checker.c \
ft_split_more.c \

SRCS_PUSH_SWAP = push_swap.c \

SRCS_CHECKER = checker_main.c \

OBJS = $(SRCS:.c=.o)

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I./Libftprintf/Libft -I./Libftprintf -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PUSH_SWAP) ./Libftprintf/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_PUSH_SWAP) ./libftprintf/libftprintf.a -o $(NAME)

checker: $(OBJS) $(OBJS_CHECKER) ./Libftprintf/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_CHECKER) -I../. ./libftprintf/libftprintf.a -o checker

./Libftprintf/libftprintf.a:
	$(MAKE) -C ./Libftprintf

clean:
	$(MAKE) -C ./Libftprintf $@
	$(RM) $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)

fclean: clean
	$(MAKE) -C ./Libftprintf $@
	$(RM) $(NAME) checker

re: fclean all

.PHONY: all clean flcean re
