#include "Zombie.hpp"

Zombie::Zombie() :name("") {};
Zombie::Zombie(std::string n) : name(n) {
};

Zombie::~Zombie() {
std::cout << "The zombie called " << this->name << " is destroyed!!!!" << std::endl;
};

void Zombie::announce( void ) {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
};