NAME = brain
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98
SRC = main.cpp
RM = rm -rf
OBJS = main.o
DEPS = $(SRC:.cpp=.d)
RED = \033[31m
RESET = \033[0m

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN) ⭐️ COMPILING ⭐️$(RESET)"

$(NAME): $(OBJS)
	@echo "$(GREEN)      🌟 Linking 🌟$(RESET)"
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) 
	@echo "$(GREEN)💫 Compiled successfully! 💫$(RESET)"

clean:
	@echo "$(RED)     🚀  Cleaning 🚀$(RESET)"
	@$(RM) $(OBJS)
	@$(RM) $(DEPS)
	@echo "$(GREEN)       🛸 Done! 🛸$(RESET)"

fclean: clean
	@echo "$(RED)     🚀  Fcleaning 🚀$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)       🛸 Done! 🛸$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re