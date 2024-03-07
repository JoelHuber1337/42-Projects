# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 16:56:09 by jhuber            #+#    #+#              #
#    Updated: 2024/02/11 16:40:13 by jhuber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)

CLIENTOFILES = $(CLIENTSRC:.c=.o)
SERVEROFILES = $(SERVERSRC:.c=.o)
CLIENTSRC = client.c
SERVERSRC = server.c

all: $(CLIENT) $(SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SERVER): $(SERVEROFILES) $(LIBFT)
		cc  -o $(SERVER) $(SERVEROFILES) $(LIBFT)

$(CLIENT): $(CLIENTOFILES) $(LIBFT)
		cc  -o $(CLIENT) $(CLIENTOFILES) $(LIBFT)

clean:
	rm -rf $(CLIENTOFILES) $(SERVEROFILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
