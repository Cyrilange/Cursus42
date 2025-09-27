#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << this->getType() << " Default contructor called" << std::endl;
    }
    
    Dog::Dog(const Dog&) : Animal("Dog") {
        std::cout << this->getType() << " Copy contructor called" << std::endl;
    }
    
    void Dog::makeSound() const {
        std::cout << BOLD_PINK << "Woaf Woaf" << RESET << std::endl;
    }
    
    Dog::~Dog() {
    std::cout << "Destructor  " << this->getType() << std::endl;
    }