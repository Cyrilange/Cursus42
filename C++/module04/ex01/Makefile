.PHONY: all clean fclean re

NAME = Animal
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) compiled"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	$(RM) $(OBJ)

fclean: clean
	@echo "Full cleaning..."
	$(RM) $(NAME)

re: fclean all
