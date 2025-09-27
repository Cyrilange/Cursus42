#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
std::cout << this->getType() << " Default contructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat&) : WrongAnimal("Wrong Cat") {
    std::cout << this->getType() << " Copy contructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << MAUVE_BOLD_ITALIC << "Quack Quack" << RESET << std::endl;
}

WrongCat::~WrongCat() {
std::cout << "Destructor  " << this->getType() << std::endl;
}