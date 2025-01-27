.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_strchr.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_printspecifier.c \
       ft_printf.c \
       ft_checksign.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f .bonus

re: fclean all