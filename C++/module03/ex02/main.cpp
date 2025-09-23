/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-20 14:21:42 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-20 14:21:42 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap z("test constr FragTrap");
    ClapTrap a;
    a.setName("Cyril"); //call default constructor
    ClapTrap c("Baba Boss");
    c.setHitpoints(200);

    ScavTrap r("Robot I92Lpq12");
    r.setAttackDamage(20);

    bool gateModeActivated = false;
    bool highFivesGuysActivated = false;

    std::cout << "\n";
    FragTrap q("Froggy");
    while (c.getHitPoints() > 0 && r.getEnergyPoints() > 0) {
        r.attack(c.getName());
        c.takeDamage(r.getAttackDamage());
        q.attack(r.getName());

        if (!gateModeActivated && r.getEnergyPoints() < 48 && q.getEnergyPoints() < 99) {
            r.guardGate();
            q.highFivesGuys();
            gateModeActivated = true;
            highFivesGuysActivated = true;
        }

        std::cout << "\n";
    }

    
    

    if (c.getHitPoints() <= 0)
        std::cout << c.getName() << " has been defeated!\n";
    else
        std::cout << r.getName() << " has no more energy!\n";

    return 0;
}
