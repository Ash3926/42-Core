NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -c

SRCS = ft_isalpha.c \
	ft_strnstr.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew_bonus.c \
	     ft_lstadd_front_bonus.c \
	     ft_lstsize_bonus.c \
	     ft_lstlast_bonus.c \
	     ft_lstadd_back_bonus.c \
	     ft_lstdelone_bonus.c \
	     ft_lstclear_bonus.c \
	     ft_lstiter_bonus.c \
	     ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all:	$(NAME)

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
	rm -f $(BONUS_OBJS)

re:	fclean all

bonus: $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
