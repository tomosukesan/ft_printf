CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME =  libftprintf.a
SRCS = ft_printf.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_chr_print.c \
	ft_str_print.c \
	ft_nbr_print.c \
	ft_unsigned_decimal.c
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