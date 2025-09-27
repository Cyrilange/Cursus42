#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"



#define BOLD_PINK   "\033[1;35m"
#define RESET       "\033[0m"

class Dog : public Animal {
    public:

    Dog();
    Dog(const Dog& other);
    virtual ~Dog();

    using Animal::operator=;
    void makeSound() const;
};

#endif