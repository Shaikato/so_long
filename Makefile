# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: randre <randre@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 23:19:57 by randre            #+#    #+#              #
#    Updated: 2023/12/26 07:00:42 by randre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long


SRC = 	        src/main.c    \
				src/file_verif.c \
				src/build.c \
				src/map_verif.c \
				src/path_verif.c \
				src/textures_init.c \
				src/display.c \
				src/mlx_init.c
				
INC = includes/so_long.h

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
MLX_DIR = /usr/local/lib
MLX:= $(MLX_DIR)/libmlx42.a -ldl -lglfw3 -pthread -lm

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C ft_printf
	@make -C get_next_line
	$(CC) $(FLAGS) $(OBJ)  libft/libft.a ft_printf/libftprintf.a get_next_line/get_next_line.a $(MLX) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@make clean -C get_next_line
	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@make fclean -C get_next_line
	rm -f $(NAME)

re: fclean all clean

.PHONY: all clean fclean re