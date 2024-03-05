NAME = push_swap

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
INC = inc/

CC = cc
CFLAGS = -Wall -Werror -Wextra -I #-fsanitize=address 
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
	@make -s all

$(LIBFT):
	@make -s -C ./libft

$(PRINTF):
	@make -s -C ./ft_printf

all: $(NAME)

$(NAME):		$(OBJ) $(LIBFT) $(PRINTF)
				ar rcs $(NAME) $(OBJ)
				@$(CC) $(CFLAGS) $(INC) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)
				@echo "$(NAME) created"

clean:

	@make clean -s -C ./libft
	@make clean -s -C ./ft_printf

fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(PRINTF)
					@echo "$(NAME) deleted"

re:				fclean all

.PHONY:				start all clean fclean re
