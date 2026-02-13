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
    ClapTrap r;
    r.setName("Rachid"); //default c
    r.setEnergyPoints(2);
    ClapTrap c("Cyril"); //parametized c
    ClapTrap m("Martin");
    ClapTrap x(m); //copy c
    x.setName("Clone of Martin");
    ClapTrap y;
    y = c; // operator
    std::cout << "\n";
    for (int i = 1; i <= 11; i++) {
        c.setAttackDamage(1);

        c.attack(m.getName());
        m.takeDamage(c.getAttackDamage());
        std::cout << "\n";
    }

    m.beRepaired(1);
    std::cout << "\n";
    r.setAttackDamage(1);
    r.attack(c.getName());
    c.takeDamage(r.getAttackDamage());
    std::cout << "\n";
    x.attack(c.getName());
    r.setAttackDamage(1);
    c.takeDamage(r.getAttackDamage());
    c.beRepaired(1); //cyril cant repair as he does not have more energy because of the attacks on Martin
    std::cout << "\n";


    return 0;
}