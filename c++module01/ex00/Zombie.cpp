#include "Zombie.hpp"

Zombie::Zombie(std::string n) : name(n) {
};
Zombie::~Zombie() {
std::cout << "Zombie destroyed" << std::endl;
};

void Zombie::announce( void ) {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
};