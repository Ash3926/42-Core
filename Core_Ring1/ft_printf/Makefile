NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -c

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all:    $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	cc $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)

re:	fclean all

.PHONY: all clean fclean re
