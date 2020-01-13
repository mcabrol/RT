# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 11:25:08 by mcabrol           #+#    #+#              #
#    Updated: 2020/01/10 23:16:36 by mcabrol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CFLAGS = -O3 # -Wall -Wextra -Werror
INC = -Iinc -Iminilibx-linux
SRC := $(shell find src -type f -regex ".*\.c")
LIB = libft/libft.a minilibx-linux/libmlx_Linux.a -lm -lmlx -lXext -lX11
FRAMEWORK = -framework OpenGL -framework AppKit
SANATIZE = -fsanitize=address

COMPILE.c = $(CC) $(CFLAGS) $(INC) $(TARGET_ARCH) -c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	# @make -C minilibx-linux
	@gcc $(CFLAGS) $(INC) $? $(LIB) -o $(NAME)

clean:
	@make clean -C libft
	# @make clean -C minilibx-linux
	@$(RM) -f $(OBJ)

fclean: clean
	@make fclean -C libft
	# @make fclean -C minilibx-linux
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
