NAME = ClapTrap
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -g -Wextra -Werror -std=c++98 -fsanitize=address

YELLOW := \033[1;33m
RESET  := \033[0m

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@clear
	@echo "$(YELLOW)Compiling...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(YELLOW)$(NAME) compiled$(RESET)"


%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)\n"
	@$(RM) $(OBJ)
	@echo "$(YELLOW)All clean!$(RESET)"

fclean: clean
	@echo "$(YELLOW)Full cleaning...$(RESET)\n"
	@$(RM) $(NAME)
	@echo "$(YELLOW)Full clean!$(RESET)"

re: fclean all