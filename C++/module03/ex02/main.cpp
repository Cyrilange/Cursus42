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

int main() {
    ClapTrap a;
    a.setName("Cyril"); //call default constructor
    ClapTrap c("Baba Boss");
    c.setHitpoints(200);

    ScavTrap r("Robot I92Lpq12");
    r.setAttackDamage(20);

    bool gateModeActivated = false;

    std::cout << "\n";

    while (c.getHitPoints() > 0 && r.getEnergyPoints() > 0) {
        r.attack(c.getName());
        c.takeDamage(r.getAttackDamage());

        if (!gateModeActivated && r.getEnergyPoints() < 48) {
            r.guardGate();
            gateModeActivated = true;
        }

        std::cout << "\n";
    }

    if (c.getHitPoints() <= 0)
        std::cout << c.getName() << " has been defeated!\n";
    else
        std::cout << r.getName() << " has no more energy!\n";

    return 0;
}
