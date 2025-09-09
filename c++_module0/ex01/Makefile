NAME = phonebook
SRC = phonebook.cpp add.cpp search.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
YELLOW := \033[1;33m
RESET  := \033[0m

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@clear
	@echo "$(YELLOW)Compiling...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)
	@echo "$(YELLOW)$(NAME) compiled$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)\n"
	@$(RM) $(NAME)
	@echo "$(YELLOW)All clean!$(RESET)"

fclean: clean

re: fclean all