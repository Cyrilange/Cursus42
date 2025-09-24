#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
    isDia = true; 
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "\033[94m" << this->getName() << " DiamondTrap default constructor called" << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap( std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() 
{
    isDia = true;
    this->Name = name; 
    HitPoints = FragTrap::HitPoints; 
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "\033[94m" << Name << " DiamondTrap parameterized constructor called\033[0m" << std::endl;
}


FragTrap::FragTrap(const FragTrap& other) :ClapTrap(other) {
    std::cout << "\033[94m" << this->getName() << " ScavTrap copy constructor called for " << Name << "\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void) {
std::cout << "\033[1;35m" << "FragTrap " << this->getName() << " ask positive high-fives " << "\033[0m" << std::endl;
}



FragTrap::~FragTrap() {
    std::cout << "\033[94m" << this->getName() << " ScavTrap destructor called for " << Name << "\033[0m" << std::endl; 
}

