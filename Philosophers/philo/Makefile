NAME = philo
cc = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c utils.c error_handling.c parse_input.c data_init.c execution.c monitoring.c monitoring_two.c philosophers.c philosophers_two.c free_functions.c
RM = rm -rf
OBJS = main.o parse_input.o utils.o error_handling.o data_init.o execution.o monitoring.o monitoring_two.o philosophers.o philosophers_two.o free_functions.o
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all: $(NAME)

$%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) ⭐️ COMPILING PHILOSOPHERS ⭐️$(RESET)"

$(NAME): $(OBJS)
	@echo "$(GREEN)      🌟 Linking 🌟$(RESET)"
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) 
	@echo "$(GREEN)💫 Compiled successfully! 💫$(RESET)"

clean:
	@echo "$(RED)     🚀  Cleaning 🚀$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)       🛸 Done! 🛸$(RESET)"

fclean: clean
	@echo "$(RED)     🚀  Fcleaning 🚀$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)       🛸 Done! 🛸$(RESET)"

re: fclean all

.PHONY: all clean fclean re