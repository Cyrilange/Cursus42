#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"



#define BOLD_PINK   "\033[1;35m"
#define RESET       "\033[0m"

class Dog : public Animal {
    public:

    Dog();
    Dog(const Dog& other);
    virtual ~Dog();

    Animal& operator=(const Dog& other);
    void makeSound() const;
    Brain& getBrain() const;
    private:

    Brain* brain;
};

#endif