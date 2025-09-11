#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sstream>

class Zombie {
    private:
    std::string	name;

	public: 
		void setName(std::string name) {  this->name = name;};
		std::string getName () const {return this->name;};

		Zombie(std::string n);
		Zombie();
		~Zombie();
		void announce( void );
        std::string create(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

  

# endif