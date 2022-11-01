CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME =  libftprintf.a
SRCS = ft_printf.c
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