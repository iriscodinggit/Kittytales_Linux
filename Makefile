NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders -g3 #-fsanitize=address

SOURCE := game_logic/controls.c game_logic/errorswalls_ext.c  game_logic/errorschars.c game_logic/graphics.c game_logic/map.c 
SOURCE2 := game_logic/so_long.c game_logic/valid_route.c game_logic/keyboard.c
GETNEXTLINE := gnliris/get_next_line_utilsi.c gnliris/get_next_linei.c
FT_PRINTF := printf/ft_printf.c printf/printf_utils.c

MLX := mlx_linux/libmlx.a

all:	$(NAME)

clean:
	make clean -C mlx_linux clean
	rm -rf $(NAME)

%.a	:
	make -C $(dir $@) all

$(NAME)	: $(MLX)
	$(CC) $(CFLAGS) $(SOURCE) $(SOURCE2) $(GETNEXTLINE) $(FT_PRINTF) -o $(NAME) -g -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11

fclean: clean
	make clean -C mlx_linux clean
	rm -rf $(NAME)

re: fclean all

.PHONY	: all clean fclean re
