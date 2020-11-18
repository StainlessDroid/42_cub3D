# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 02:24:10 by mpascual          #+#    #+#              #
#    Updated: 2020/11/18 01:43:36 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c #...

OBJS = $(SRC:.c=.o)

TEST_FILE = pruebas.c

LIB_PATH = libft_printf/libftprintf.a

MLX_PATH = mlx_linux/libmlx_Linux.a

MLX = -lmlx -lXext -lX11

$(NAME): $(OBJS) lib
	gcc -o $(NAME) $(OBJS) $(MLX) -L. $(LIB_PATH) $(MLX_PATH)

all: $(NAME)

lib:
	cd libft_printf && make re && make clean && cd ../
	cd mlx_linux && ./configure && cd ../

norme:
	@norminette src/*.c
	@norminette libft_printf/*.c

test: $(OBJS)
	gcc -o $(NAME) TEST_FILE:.c=.o -L. $(LIB)

clean:
	rm -rf $(OBJS)
	cd libft_printf && make clean && cd ../
	rm -rf mlx_linux/*.o test

fclean: clean
	rm -rf $(NAME) $(LIB_PATH) $(MLX_PATH)

re: fclean all

.PHONY: fclean
