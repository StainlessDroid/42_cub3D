# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 02:24:10 by mpascual          #+#    #+#              #
#    Updated: 2020/11/16 02:50:34 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c #...

OBJS = $(SRC:.c=.o)

TEST_FILE = pruebas.c

LIB = libs/libft/libft_full.a lib/mlx_linux/libmlx_Linux.a

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -L. $(LIB)

all: $(NAME)

norme:
	@norminette src/

test: $(OBJS)
	gcc -o $(NAME) TEST_FILE:.c=.o -L. $(LIB)

clean:
	rm -rf $(OBJS)
	rm -rf $(LIB)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean
