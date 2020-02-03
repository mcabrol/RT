# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 11:25:08 by mcabrol           #+#    #+#              #
#    Updated: 2020/01/15 15:56:54 by mcabrol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CFLAGS = -O3 -Wall -Wextra -Werror
INC = -Iinc -Iminilibx
SRC := $(shell find src -type f -regex ".*\.c")
LIB = libft/libft.a minilibx/libmlx.a # -lm -lmlx -lXext -lX11
FRAMEWORK = -framework OpenCL -framework OpenGL -framework AppKit
SANATIZE = -fsanitize=address

COMPILE.c = $(CC) $(CFLAGS) $(INC) $(TARGET_ARCH) -c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx
	@gcc $(CFLAGS) $(INC) $? $(LIB) $(FRAMEWORK) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C minilibx
	@$(RM) -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C minilibx
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
