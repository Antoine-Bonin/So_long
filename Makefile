.PHONY := all clean fclean re valgrind init

NAME := process

CC := cc

CFLAGS := -Werror -Wextra -Wall -g3

SRCS := So_long/draw_map.c \
	So_long/handle_keypress.c \
	So_long/mapping.c \
	So_long/check_mapping.c \
	So_long/so_long.c \
	So_long/textures.c \
	So_long/check_wall.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	libft/ft_checksign.c \
	libft/ft_printf.c \
	libft/ft_printspecifier.c \
	libft/ft_putchar_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_strchr.c \

OBJS := $(SRCS:.c=.o)

LIBS := -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

init:
	$(MAKE) re
	$(MAKE) clean
