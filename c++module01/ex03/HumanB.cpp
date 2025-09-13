#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n), weapon(NULL) {}

HumanB::HumanB() : name(""), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& w) {
    weapon = &w;
}

void HumanB::attack() {
    if (weapon)
        std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << getName() << " has no weapon!" << std::endl;
}
