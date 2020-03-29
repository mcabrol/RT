# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 11:25:08 by mcabrol           #+#    #+#              #
#    Updated: 2020/03/11 19:22:47 by mcabrol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CFLAGS = -O3 -Wall -Wextra -Werror
INC = -Iinc -Ilib/minilibx -Ilib/libft/inc -Ilib/libmath
SRC := $(shell find src -type f -regex ".*\.c")
LIB = lib/libft/libft.a lib/minilibx/libmlx.a lib/libmath/libmath.a
FRAMEWORK = -framework OpenGL -framework AppKit -lz
SANATIZE = -fsanitize=address

COMPILE.c = $(CC) $(CFLAGS) $(INC) $(TARGET_ARCH) -c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) libs
	@gcc $(CFLAGS) $(INC) $(OBJ) $(LIB) $(FRAMEWORK) -o $(NAME) #$(SANATIZE)

libs:
	make -C lib/libft/
	make -C lib/minilibx/
	make -C lib/libmath/

clean:
	make clean -C lib/libft/
	make clean -C lib/minilibx/
	make clean -C lib/libmath/

	$(RM) -f $(OBJ)

fclean: clean
	make fclean -C lib/libft/
	make fclean -C lib/minilibx/
	make fclean -C lib/libmath/
	$(RM) -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
