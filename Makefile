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
	ft_address_print.c
SRCS_BONUS = ft_printf_bonus.c \
	ft_cal_digit_bonus.c \
	ft_check_flag_bonus.c \
	ft_decimal_print_bonus.c \
	ft_hex_print_bonus.c \
	ft_nbr_print_bonus.c \
	ft_nbr_put_flags_bonus.c \
	ft_address_bonus.c \
	ft_str_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
ifdef WITH_BONUS
OBJS += $(OBJS_BONUS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

bonus:
	@make WITH_BONUS=1
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)

re: clean fclean all

.PHONY: clean fclean all re bonus