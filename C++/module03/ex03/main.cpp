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
#include "DiamondTrap.hpp"

int main() {

    DiamondTrap d;
    ScavTrap b;
    d.setName("Madara");
    b.setName("Krilin");

    std::cout << "\n\n";
    d.attack(b.getName());
    b.takeDamage(b.getAttackDamage());
    b.beRepaired(b.getEnergyPoints());

    std::cout << "\n";
    b.attack(d.getName());
    d.whoAmI();

    std::cout << "\n\n";

    return 0;
}
