#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

class Zombie {
    private:
    std::string	name;

	public: 
		std::string setName(std::string name) { return this->name = name;};
		std::string getName () const {return this->name;};

		Zombie(std::string n);
		Zombie();
		~Zombie();
		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );