#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    using ClapTrap::operator=;
    void attack(const std::string& target);
    void guardGate();
    ~ScavTrap();



};

#endif

