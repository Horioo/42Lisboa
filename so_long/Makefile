NAME = so_long

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
MLX = mlx_linux/libmlx.a
INC = inc/

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I #-fsanitize=address
MLX_FLAGS = -lmlx -lXext -lX11
RM = rm -f

FILES = 	so_long.c \
			utils.c \
			map_render.c \
			player_move.c \
			enemy.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c


SRCS = $(FILES)

OBJ = $(SRCS:.o=.c)


$(LIBFT):
	@make -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(MLX):
	@make -C ./mlx_linux


all: $(NAME)

$(NAME):		$(OBJ) $(LIBFT) $(PRINTF)
				@ar rcs $(NAME) $(OBJ)
				$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(MLX) -o $(NAME)
				@echo "$(NAME) created"
clean:

	make clean -C ./libft
	make clean -C ./ft_printf

fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(PRINTF)
					@echo "$(NAME) deleted"

re:				fclean all

.PHONY:				start all clean fclean re
