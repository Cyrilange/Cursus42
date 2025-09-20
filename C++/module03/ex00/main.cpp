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

int main() {
    ClapTrap c;
    ClapTrap m;
    c.setName(" Cyril");
    m.setName(" Martin");
    ClapTrap z(c);
   c.setAttackDamage(1);
    c.setEnergyPoints(3);
    c.setHitpoints(1);
    m.setHitpoints(1);
    c.attack(m.getName());
    m.takeDamage(1);
    m.beRepaired(1);
    return 0;
}