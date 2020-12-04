# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 02:24:10 by mpascual          #+#    #+#              #
#    Updated: 2020/12/01 02:19:53 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To include bonus in compilation call makefile with "WITH_BONUS=1" argument

NAME = cub3D
REG_SRC_FILES = src/main.c src/utils.c
BONUS_SRC_FILES = src/bonus/*.o
HEADER = cub3d.h
LIB_PATH = libft_printf/libftprintf.a
MLX_FLAGS = -lmlx -lXext -lX11
CFLAGS = -Wall -Wextra #-Werror

ifdef WITH_BONUS
SRC = $(REG_SRC_FILES) $(BONUS_SRC_FILES)
else
SRC = $(REG_SRC_FILES)
endif

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -L. $(LIB_PATH)

lib:
	cd libft_printf && make re && make clean && cd ../

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:
	$(MAKE) WITH_BONUS=1 all

norme: clean
	@norminette $(SRC)

.PHONY: all clean fclean re