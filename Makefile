# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 16:27:12 by ttikanoj          #+#    #+#              #
#    Updated: 2023/06/11 10:48:48 by tuukka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./fdf.c fdf_utils.c createmap.c draw.c coords.c coords_utils.c

OBJ = ./fdf.o fdf_utils.o createmap.o draw.o coords.o coords_utils.o

HEADERS = -I ./mlx

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	cc $(FLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	cc $(FLAGS) $(OBJ) -Lmlx -lmlx -L./libft -lft -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C mlx
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all
