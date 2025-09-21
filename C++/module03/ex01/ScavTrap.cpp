#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") {
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "\033[94m" << this->getName() << " ScavTrap default constructor called" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "\033[94m" << this->getName() << " ScavTrap parameterized constructor called for " << Name << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) :ClapTrap(other) {
    std::cout << "\033[94m" << this->getName() << " ScavTrap copy constructor called for " << Name << "\033[0m" << std::endl;
}
