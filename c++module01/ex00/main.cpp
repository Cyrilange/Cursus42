#include "Zombie.hpp"
Zombie::Zombie() : name("") {}

int main(void) {
    
    std::string prompt;
    if (!std::getline(std::cin, prompt))
        return - 1; 
    std::cout << "\n";
    system("clear");
   
    randomChump(prompt);
   
    return 0;
    
} 