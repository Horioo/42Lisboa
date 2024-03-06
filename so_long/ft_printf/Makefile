NAME = libftprintf.a

CC = cc

SRC = ft_printf.c\
	ft_printf_formats.c\
	

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

RM = rm -f

all: $(NAME)

$(NAME):	$(LIBFT) $(OBJ)
		@ar rcs $(NAME) $(OBJ) libft/libft.a
		@echo "$(NAME) created"

$(LIBFT):
		@make -C $(LIBFT_PATH)

clean:
		@$(RM) $(OBJ)
		@make -C $(LIBFT_PATH) clean
		
fclean: clean
		@$(RM) $(NAME) ft_printf
		@make -C $(LIBFT_PATH) fclean
		@echo "$(NAME) and $(LIBFT_PATH) deleted"

re: fclean all

.PHONY: all clean fclean