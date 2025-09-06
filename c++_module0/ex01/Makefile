NAME = phonebook
SRC = phonebook.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re