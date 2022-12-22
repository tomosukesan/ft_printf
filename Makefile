# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 10:33:04 by ttachi            #+#    #+#              #
#    Updated: 2022/12/22 12:03:42 by ttachi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME =  libftprintf.a
SRCS = ft_printf.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_chr_print.c \
	ft_str_print.c \
	ft_nbr_print.c \
	ft_decimal_print.c \
	ft_hex_print.c \
	ft_address_print.c
SRCS_BONUS = ./bonus/ft_printf_bonus.c \
	./bonus/ft_address_print_bonus.c \
	./bonus/ft_chr_print_bonus.c \
	./bonus/ft_decimal_print_bonus.c \
	./bonus/ft_hex_print_bonus.c \
	./bonus/ft_hex_flag_bonus.c \
	./bonus/ft_nbr_print_bonus.c \
	./bonus/ft_nbr_flag_bonus.c \
	./bonus/ft_putchar_fd_bonus.c \
	./bonus/ft_putnbr_fd_bonus.c \
	./bonus/ft_putstr_fd_bonus.c \
	./bonus/ft_str_print_bonus.c \
	./bonus/ft_strlen_bonus.c \
	./bonus/ft_cal_digit_bonus.c \
	./bonus/ft_check_flag_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
ifdef WITH_BONUS
	OBJS = $(OBJS_BONUS)
endif

all: preprocess $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

preprocess:
ifdef WITH_BONUS
	@if find . -name $(NAME) && nm -u $(NAME) | grep ft_printf.o; then $(RM) $(NAME); fi;
else
	@if find . -name $(NAME) && nm -u $(NAME) | grep bonus; then $(RM) $(NAME); fi;
endif

bonus:
	@make WITH_BONUS=1
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus preprocess
