.PHONY := all clean fclean re init

NAME := so_long
CC := cc
CFLAGS := -Werror -Wextra -Wall -g3 
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

OBJ_DIR = obj/
OBJ_SO_LONG = $(OBJ_DIR)So_long/
OBJ_GNL = $(OBJ_DIR)gnl/

SRCS := So_long/draw_map.c \
	So_long/handle_keypress.c \
	So_long/mapping.c \
	So_long/check_mapping.c \
	So_long/so_long.c \
	So_long/textures.c \
	So_long/check_wall.c \
	So_long/init_game.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \

OBJS := $(patsubst So_long/%.c,$(OBJ_SO_LONG)%.o,$(filter So_long/%.c,$(SRCS))) \
        $(patsubst gnl/%.c,$(OBJ_GNL)%.o,$(filter gnl/%.c,$(SRCS)))

DEPS = $(LIBFT_DIR)ressource/libft.h
LIBS := -Lminilibx-linux -lmlx_Linux -lX11 -lXext
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) ./So_long/so_long.h
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT) -o $(NAME)

$(OBJ_SO_LONG)%.o: So_long/%.c $(DEPS)
	@mkdir -p $(OBJ_SO_LONG)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_GNL)%.o: gnl/%.c
	@mkdir -p $(OBJ_GNL)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)libft/*.c $(DEPS)
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all

init:
	$(MAKE) re
	$(MAKE) clean
