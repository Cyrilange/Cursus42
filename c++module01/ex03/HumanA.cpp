#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon& w) : name(n), weapon(&w) {};

HumanA::HumanA() : name(" "), weapon(NULL) {};

HumanA::~HumanA() {};

void HumanA::attack() {
    std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}; 