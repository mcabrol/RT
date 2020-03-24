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
INC = -Iinc -Iminilibx -Ilibft/inc -Ilibmath
SRC := $(shell find src -type f -regex ".*\.c")
LIB = libft/libft.a minilibx/libmlx.a libmath/libmath.a
FRAMEWORK = -framework OpenGL -framework AppKit -lz
SANATIZE = -fsanitize=address

COMPILE.c = $(CC) $(CFLAGS) $(INC) $(TARGET_ARCH) -c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) lib
	@gcc $(CFLAGS) $(INC) $(OBJ) $(LIB) $(FRAMEWORK) -o $(NAME) #$(SANATIZE)

lib:
	make -C ./libft
	make -C ./minilibx
	make -C ./libmath

clean:
	make clean -C libft
	make clean -C minilibx
	make clean -C libmath

	$(RM) -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C minilibx
	make fclean -C libmath
	$(RM) -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
