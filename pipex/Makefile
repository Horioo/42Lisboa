NAME = pipex

LIBFT = libft/libft.a
INC = inc/

CC = cc -Wall -Werror -Wextra
RM = rm -f

FILES = pipex.c \
		others.c

SRCS = $(FILES)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C ./libft

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(OBJ) $(LIBFT) -o $(NAME)
			@echo "$(NAME) created"

clean:
	@make -C ./libft fclean --no-print-directory

fclean:		clean
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)
				@$(RM) *.o
				@echo "$(NAME) deleted"

re:			fclean all

.PHONY:			start all clean fclean re