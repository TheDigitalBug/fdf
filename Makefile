# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 10:15:44 by kkotliar          #+#    #+#              #
#    Updated: 2017/08/17 10:25:52 by kkotliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAG = -Wall -Werror -Wextra -framework OpenGL -framework AppKit

OBJ = ft_draw_line.o \
	  ft_readmap.o \
	  fdf.o \
	  ft_color.o \
	  ft_gradient.o \
	  ft_valid_map.o \
	  ft_draw_info.o \
	  ft_key.o

HEADER = fdf.h

LIB = libft/libft.a
LIBM = minilibx/libmlx.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C minilibx
	$(CC)  $^ $(CFLAG) $(LIBM) $(LIB) -o $@

clean:
	make clean -C ./libft
	make clean -C ./minilibx
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft
	make re -C ./minilibx
