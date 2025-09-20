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
    ClapTrap c("Cyril");
    ClapTrap m("Martin");
    std::cout << "\n";
    for (int i = 1; i <= 11; i++) {
        c.setAttackDamage(1);

        c.attack(m.getName());
        m.takeDamage(c.getAttackDamage());
        std::cout << "\n";
    }

    m.beRepaired(1);
    std::cout << "\n";


    return 0;
}