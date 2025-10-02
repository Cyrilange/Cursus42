#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
std::cout << this->getType() << " Default contructor called" << std::endl;
this->brain = new Brain();

}

Cat::Cat(const Cat& other) : Animal("Cat") {
    std::cout << this->getType() << " Copy contructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Animal& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other); 
        *this->brain = *other.brain;
    }
    return *this;
}

Brain& Cat::getBrain() const {
    return *brain;
}

void Cat::makeSound() const {
    std::cout << BOLD_YELLOW << "Meow Meow" << RESET << std::endl;
}

Cat::~Cat() {
std::cout << "Destructor  " << this->getType() << std::endl;
delete brain;
}