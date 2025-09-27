#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

#define BOLD_YELLOW "\033[1;33m"
#define RESET       "\033[0m"


class Cat : public Animal {
    public:

    Cat();
    Cat(const Cat& other);
    virtual ~Cat();

    using Animal::operator=;
    void makeSound() const;
};

#endif