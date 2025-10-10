/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:58:35 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:58:35 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon& w) : name(n), weapon(&w) {};

HumanA::HumanA() : name(" "), weapon(NULL) {};

std::string HumanA::getName(void) {return this->name;};
      
void HumanA::setName(std::string n) {this->name = n;};

HumanA::~HumanA() {};

void HumanA::attack() {
    std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}; 