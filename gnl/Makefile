.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = gnl.a

SRCS = get_next_line.c \
		get_next_line_utils.c \

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
