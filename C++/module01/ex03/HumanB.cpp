/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:58:42 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:58:42 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n), weapon(NULL) {}

HumanB::HumanB() : name(""), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& w) {
    weapon = &w;
}

std::string HumanB::getName() {return this->name;};
       
void HumanB::setName(std::string n) {this->name = n;};

void HumanB::attack() {
    if (weapon)
        std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << getName() << " has no weapon!" << std::endl;
}
