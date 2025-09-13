#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
class Weapon;


class HumanA {

    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanA();
        HumanA(std::string n, Weapon& w);

        ~HumanA();
        std::string getName(void) {return this->name;};
      
        void setName(std::string n) {this->name = n;};
        void attack();
};



#endif