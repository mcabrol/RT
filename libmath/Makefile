SRC_FILE = matrix matrix_2 operator operator_2 point_matrix \
			vector vector_2 vector_matrix
SRCS = $(addsuffix .c, $(SRC_FILE))
OBJ = $(SRCS:.c=.o)
OBJS = $(SRCS:%.c=%.o)
NAME = libmath.a
FLAG = -Wall -Werror -Wextra
LIBFT=-I../libft

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creation de : $(NAME)"
	@ar rc $(NAME) $(OBJ)
	@echo "Indexage de : $(NAME)"
	@ranlib $(NAME)


.PHONY: clean fclean re

clean:
	@echo "Suppression de : $(OBJS)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "Suppression de : $(NAME)"
	@$(RM) $(NAME)

re: fclean all
