NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98
SRC = PhoneBook.cpp HelperFunctions.cpp main.cpp Contact.cpp
RM = rm -rf
OBJS = PhoneBook.o HelperFunctions.o main.o Contact.o
RED = \033[31m
DEPS = $(SRC:.cpp=.d)
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
