#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    using ClapTrap::operator=;
    using ClapTrap::attack;
    void guardGate();
    ~ScavTrap();



};

#endif

