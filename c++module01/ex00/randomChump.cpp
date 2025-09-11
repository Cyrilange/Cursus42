#include "Zombie.hpp"

/*This function creates a zombie, names it, and makes it announce itself.*/

void randomChump( std::string name ) {
    Zombie* newZ = newZombie(name);
    newZ->announce();
    usleep(100);
    delete newZ;
};
