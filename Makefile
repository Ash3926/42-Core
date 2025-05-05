NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -c

SRCS := $(wildcard ft_*.c)

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
        cc $(CFLAGS) $< -o $@

clean:
	rm $(OBJS)

fclean:
	rm $(NAME)
	rm $(OBJS)

re:	fclean all

.PHONY: all clean fclean re
