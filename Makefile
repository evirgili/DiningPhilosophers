
NAME		= philo

SRC			=	src/main.c\
				src/actions.c\
				src/start_pthread.c\
				src/init_print.c\
				src/init_time.c\
				src/utils.c\


OBJ			= $(SRC:.c=.o)
CFLAGS		= -Wall -Wextra -Werror
SANITIZE	= -fsanitize=address
INC			= includes/

.c.o:
	gcc $(CFLAGS) -I$(INC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(HDR)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	norminette **/*.c
	norminette srcs/**/*.c
	norminette **/*.h

.PHONY: all clean fclean re
