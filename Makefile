CC = cc

NAME = push_swap

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

OPTION = -c

SRC = 	function.c parser/check_number.c parser/parser.c parser/strategy_parser.c

OBJ = $(SRC:.c=.o)

all: ${NAME}

$(NAME): ${OBJ}
	${CC} ${OBJ} libft/libft.a -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re

