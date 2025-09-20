#include "ClapTrap.hpp"

int main() {
    ClapTrap n;
   n.setName("csdavewev");
    n.setAttackDamage(26);
    ClapTrap b(n); 
    b.setName("Cyril");
    int at = n.getAttackDamage();


    
    std::cout << at << std::endl ;
    return 0;
}