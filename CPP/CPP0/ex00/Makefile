NAME = megaphone
SRC = megaphone.cpp
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@clear
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo  "$(GREEN)Compilation complete!$(RESET)"

clean:
	@rm -f $(NAME)
	@echo  "$(GREEN)Cleanup complete!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo  "$(GREEN)Executable removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
