# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 11:25:08 by mcabrol           #+#    #+#              #
#    Updated: 2020/01/10 20:48:26 by mcabrol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CFLAGS = -O3 -Wall -Wextra -Werror
INC = -Iinc

SRC := $(shell find src -type f -regex ".*\.c")

COMPILE.c = $(CC) $(CFLAGS) $(INC) $(TARGET_ARCH) -c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a .
	@gcc $(CFLAGS) $(INC) $(OBJ) libft.a -o $(NAME)

clean:
	@make clean -C libft
	@$(RM) -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@$(RM) -f $(NAME)
	@$(RM) -f libft.a

re: fclean all

.PHONY: clean fclean all re
