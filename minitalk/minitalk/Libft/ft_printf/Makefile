# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 18:19:14 by jhuber            #+#    #+#              #
#    Updated: 2023/10/06 23:38:49 by jhuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT_DIR)

OFILES = $(SRC:.c=.o)
SRC = ft_special.c ft_printf.c ft_printhex.c

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OFILES) $(LIBFT)
		cp $(LIBFT) $(NAME)
		ar 	rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re