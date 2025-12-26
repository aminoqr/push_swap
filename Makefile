NAME = 		push_swap
CC = 		cc
CFLAGS = 	-Wall -Werror -Wextra
RM = 		rm -f

SRC = 		main.c push.c reverse_rotate.c rotate.c sort_utils.c \
			stack_utils.c stack_utils2.c swap.c turk_algo.c turk_algo2.c \
			libft_utils.c libft_utils2.c

OBJ = 		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re