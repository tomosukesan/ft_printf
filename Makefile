CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME =  libftprintf.a
SRCS = ft_printf.c \
	ft_strlen.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_chr_print.c \
	ft_str_print.c \
	ft_nbr_print.c \
	ft_decimal_print.c \
	ft_handle_hex.c \
	ft_hex_print.c \
	ft_address_print.c \
	ft_check_flag.c \
	ft_cal_digit.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: clean fclean all

.PHONY: clean fclean all re