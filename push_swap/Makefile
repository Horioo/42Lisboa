NAME = push_swap

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
INC = inc/

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -I
RM = rm -f

COMMANDS = stack_moves/push.c \
			stack_moves/algorithm.c \
			stack_moves/rev_rotate.c \
			stack_moves/rotate.c \
			stack_moves/sort_three.c \
			stack_moves/swap.c

REST = check_errors.c \
		init_a.c \
		init_b.c \
		init_stack.c \
		push_swap.c \
		split.c \
		stack_utils.c \
		stack_utils2.c

SRCS = $(COMMANDS) $(REST)

OBJ = $(SRCS:.o=.c)

start: 
	make all

$(LIBFT):
	@make -C ./libft

$(PRINTF):
	@make -C ./ft_printf

all: $(NAME)

$(NAME):		$(OBJ) $(LIBFT) $(PRINTF)
				@ar rcs $(NAME) $(OBJ)
				$(CC) $(CFLAGS) $(INC) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

clean:

	make clean -C ./libft
	make clean -C ./ft_printf

fclean:			clean
					$(RM) $(NAME)
					$(RM) $(LIBFT)
					$(RM) $(PRINTF)

re:				fclean all

.PHONY:				start all clean fclean re
