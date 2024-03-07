# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:56:09 by jhuber            #+#    #+#              #
#    Updated: 2024/02/25 17:17:55 by jhuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)

OFILES = $(SRC:.c=.o)
SRC = so_long.c check_map.c convert_map.c error_handling.c flood_check.c get_textures.c start_game.c keyboard_config.c exits.c

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OFILES) $(LIBFT)
		cc  -o $(NAME) $(OFILES) $(LIBFT) -lmlx -lXext -lX11 -lm

clean:
	rm -rf $(OFILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re