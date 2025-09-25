#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
    isDia = true; 
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "\033[94m" << this->getName() << " DiamondTrap default constructor called" << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap() , ScavTrap() 
{
    isDia = true;
    this->Name = name; 
    HitPoints = FragTrap::HitPoints; 
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "\033[94m" << Name << " DiamondTrap parameterized constructor called\033[0m" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap& other) :ClapTrap(other),  FragTrap(other), ScavTrap(other) {
    isDia = true;
    this->Name = other.Name; 
    this->HitPoints = other.FragTrap::HitPoints; 
    this->EnergyPoints = other.ScavTrap::EnergyPoints;
    this->AttackDamage = other.FragTrap::AttackDamage;
    std::cout << "\033[94m" << this->getName() << " DiamondTrap copy constructor called for " << Name << "\033[0m" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "\033[38;5;208m " << "I am" << this->getName() << " and I am a " << this->DiamondTrap::getName() << "\033[0m" << std::endl;
    std::cout << "\033[38;5;208m " << "I am" << this->getName() << " and I am a " << this->ClapTrap::getName() << "\033[0m" << std::endl;

}

DiamondTrap::~DiamondTrap() {
    std::cout << "\033[94m" << this->getName() << " DiamondTrap destructor called for " << Name << "\033[0m" << std::endl; 
}

 