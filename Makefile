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

NAME = libui.a
SDL2 = SDL2-2.0.10
CFLAGS = -O3 -Wall -Wextra -Werror
INC = -Iinc
SRC := $(shell find src -type f -regex ".*\.c")

COMPILE.c = $(CC) $(CFLAGS) $(INC) $(TARGET_ARCH) -c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(SDL2)
	@make -C libft
	@cp libft/libft.a .
	@ar -rc $(NAME) $?
	@ranlib $(NAME)

compile:
	@gcc $(CFLAGS) $(INC) -I$(SDL2)/include $(OBJ) -L$(SDL2)/build/.libs -lSDL2 libft.a main.c -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C $(SDL2)
	@$(RM) -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@$(RM) -f $(NAME)
	@$(RM) -f libft.a

re: fclean all

.PHONY: clean fclean all re
