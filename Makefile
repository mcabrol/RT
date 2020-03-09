# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 11:25:08 by mcabrol           #+#    #+#              #
#    Updated: 2020/03/09 17:15:16 by judrion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CFLAGS = -O3 -Wall -Wextra -Werror
INC = -Iinc -Iminilibx -Ilibmath
SRC := $(shell find src -type f -regex ".*\.c")
LIB = libft/libft.a minilibx/libmlx.a libmath/libmath.a # -lm -lmlx -lXext -lX11
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
	$(RM) -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C minilibx
	$(RM) -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
