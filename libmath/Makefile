SRC_FILE = matrix matrix_2 point_matrix \
			 vector_matrix operator vector #operator_2 vector vector_2
SRCS = $(addsuffix .c, $(SRC_FILE))
OBJ = $(SRCS:.c=.o)
OBJS = $(SRCS:%.c=%.o)
NAME = libmath.a
FLAG = -Wall -Werror -Wextra

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
