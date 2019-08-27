# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 10:37:38 by rsmith            #+#    #+#              #
#    Updated: 2019/08/19 15:17:59 by rsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCDIR = ./sources/

SRC = images.c \
main.c \
hooks.c \
math.c \
help.c \

 OBJECTS = $(SRC:.c=.o)

 INC = includes

 CC = gcc
 CFLAGS = -Wall -Wextra -Werror

 FRAMEWORK = -framework OpenGL -framework AppKit

 LIBFT = libft/libft.a

 MLX = minilibx_macos/libmlx.a

 .PHONY: all
 all: $(NAME)

 $(NAME):
	@make -C libft
	@make -C minilibx_macos
	@echo "making"
	@$(CC) $(CFLAGS) -c $(addprefix $(SRCDIR), $(SRC)) -I $(INC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(MLX) $(FRAMEWORK)

.PHONY: clean
clean:
	@echo "cleaning"
	@/bin/rm -f $(OBJECTS)
	@make -C libft clean
	@make -C minilibx_macos clean
.PHONY: fclean
fclean : clean
	rm -rf $(NAME)
	make -C libft fclean
.PHONY: re
re: fclean all
