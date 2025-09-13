#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon {
    private:
        std::string type;
    public:

    Weapon();
    Weapon(std::string t);
    ~Weapon();
    std::string getType() {return this->type;};
    void setType(std::string t) { this->type = t;};
};

# endif