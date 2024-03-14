NAME = so_long

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
MLX = minilibx-linux/libmlx.a
INC = inc/

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I #-fsanitize=address
MLX_FLAGS = -lmlx -lXext -lX11
RM = rm -f

FILES = 	srcs/so_long.c \
			srcs/error_handling.c \
			srcs/error_handling_2.c \
			srcs/init_game.c \
			srcs/init_game_2.c \
			srcs/map_render.c \
			srcs/player_move.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c


SRCS = $(FILES)

OBJ = $(SRCS:.o=.c)


$(LIBFT):
	@make -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(MLX):
	@$(MAKE) -C ./minilibx-linux


all: $(NAME)

$(NAME):		$(OBJ) $(LIBFT) $(PRINTF) $(MLX)
				@ar rcs $(NAME) $(OBJ)
				$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(MLX) -o $(NAME)
				@echo "$(NAME) created"
clean:

	@make -C ./libft fclean --no-print-directory
	@make clean -C ./ft_printf

fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(PRINTF)
					@$(RM) $(MLX)
					@echo "$(NAME) deleted"

re:				fclean all

.PHONY:				start all clean fclean re
