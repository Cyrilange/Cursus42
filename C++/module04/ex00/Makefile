.PHONY: all clean fclean re banner

NAME = Animal
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

PINK_BOLD_ITALIC := \033[1;3;95m
YELLOW := \033[1;33m
RESET := \033[0m

banner:
	@clear
	@echo "$(PINK_BOLD_ITALIC)"
	@echo " _______  __    _  ___   __   __  _______  ___     "
	@echo "|   _   ||  |  | ||   | |  |_|  ||   _   ||   |    "
	@echo "|  |_|  ||   |_| ||   | |       ||  |_|  ||   |    "
	@echo "|       ||       ||   | |       ||       ||   |    "
	@echo "|       ||  _    ||   | |       ||       ||   |___ "
	@echo "|   _   || | |   ||   | | ||_|| ||   _   ||       |"
	@echo "|__| |__||_|  |__||___| |_|   |_||__| |__||_______|"
	@echo  "$(RESET)"

all: banner $(NAME)

$(NAME): $(OBJ)
	@echo  "$(YELLOW)Compiling...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo  "$(YELLOW)$(NAME) compiled$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo -e "$(YELLOW)Cleaning...$(RESET)"
	@$(RM) $(OBJ)

fclean: clean
	@echo -e "$(YELLOW)Full cleaning...$(RESET)"
	@$(RM) $(NAME)

re: fclean all
