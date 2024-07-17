NAME		= push_swap

SRC		= $(addprefix src/, main.c parse_input.c free.c parse_utils.c list_utils.c push_swap.c swap.c \
			rotate.c rev_rotate.c push.c)

OBJ		= $(SRC:.c=.o)

LIBFT_PATH	= libft/

LIBFT_NAME	= libft.a

LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

CC		= cc

RM 		= rm -f

CFLAGS		= -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re valgrind
