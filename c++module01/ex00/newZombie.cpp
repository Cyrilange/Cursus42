
#include "Zombie.hpp"

/*
This function creates a zombie
My choice is to use the heap with the new and delete*/

Zombie* newZombie( std::string name ) {
    Zombie* newZ = new Zombie(name); 
    return newZ;
};