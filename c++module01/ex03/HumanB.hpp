#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
class Weapon;

class HumanB {
    private:
        std::string name;
        Weapon* weapon;
    
    public:
        HumanB(std::string n);
        HumanB();
        ~HumanB();
        std::string getName() {return this->name;};
       
        void setName(std::string n) {this->name = n;};
        void setWeapon(Weapon& w);
       void attack();
        
};




#endif