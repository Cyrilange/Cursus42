#ifndef DIAMONTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
    DiamondTrap();
        DiamondTrap(std::string& name);
        DiamondTrap(const DiamondTrap& other);
        using ClapTrap::operator=;
        using ClapTrap::attack;
        void whoAmI();
        ~DiamondTrap();

    private:

        std::string Name;
    };

#endif