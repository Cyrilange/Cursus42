#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
std::cout << this->getType() << " Default contructor called" << std::endl;
}

Cat::Cat(const Cat&) : Animal("Cat") {
    std::cout << this->getType() << " Copy contructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << BOLD_YELLOW << "Meow Meow" << RESET << std::endl;
}

Cat::~Cat() {
std::cout << "Destructor  " << this->getType() << std::endl;
}