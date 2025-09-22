#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") {
    isScav = true; 
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "\033[94m" << this->getName() << " ScavTrap default constructor called" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    isScav = true; 
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "\033[94m" << this->getName() << " ScavTrap parameterized constructor called for " << Name << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) :ClapTrap(other) {
    std::cout << "\033[94m" << this->getName() << " ScavTrap copy constructor called for " << Name << "\033[0m" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() 
              << " is now in Gate keeper mode" << std::endl;

    this->AttackDamage = static_cast<int>(this->AttackDamage * 1.5);

    if (this->EnergyPoints > 0)
        this->EnergyPoints = this->EnergyPoints - 4;

    std::cout << "ScavTrap " << this->getName() 
              << " now has AttackDamage: " << this->AttackDamage
              << " and EnergyPoints: " << this->EnergyPoints << std::endl;
}


ScavTrap::~ScavTrap() {
    std::cout << "\033[94m" << this->getName() << " ScavTrap destructor called for " << Name << "\033[0m" << std::endl; 
}


