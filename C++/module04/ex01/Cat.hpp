#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

#define BOLD_YELLOW "\033[1;33m"
#define RESET       "\033[0m"


class Cat : public Animal {
    public:

    Cat();
    Cat(const Cat& other);
    virtual ~Cat();

    Animal& operator=(const Cat& other);
    Brain& getBrain() const;
    void makeSound() const;

    private:

    Brain* brain;
};

#endif