# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:56:09 by jhuber            #+#    #+#              #
#    Updated: 2024/02/03 21:22:23 by jhuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)

OFILES = $(SRC:.c=.o)
SRC = functions.c functions_two.c functions_three.c functions_four.c error_handling.c push_swap.c target_sort.c make_nodes.c stack_functions.c make_nodes_b.c fill_stack_a.c

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OFILES) $(LIBFT)
		cc  -o $(NAME) $(OFILES) $(LIBFT)

clean:
	rm -rf $(OFILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re