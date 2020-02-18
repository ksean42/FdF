# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksean <ksean@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 17:05:18 by ksean             #+#    #+#              #
#    Updated: 2020/02/18 21:11:06 by ksean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH = srcs/

SRC =	$(PATH)main.c\
		$(PATH)read.c\
		$(PATH)drawing.c\
		$(PATH)controls.c\
		$(PATH)utils.c\
		$(PATH)utils2.c

OBJ = $(SRC:.c=.o)
LIB = libft.a
LIB_PATH := ./libft/
MLX_PATH = minilibx_macos/

FLAGS = -Wall -Wextra -Werror -g

NAME = fdf

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)libft.a $(MLX_PATH)libmlx.a \
		-framework OpenGL -framework AppKit

$(LIB):
		make -C $(LIB_PATH)
		make -C $(MLX_PATH)

$(OBJ): %.o: %.c
		gcc $(FLAGS) -I ./includes -I $(LIB_PATH) -I $(MLX_PATH) -o $@ -c $^

clean:
		rm -rf $(OBJ)
		make clean -C $(LIB_PATH)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME)

re: fclean all