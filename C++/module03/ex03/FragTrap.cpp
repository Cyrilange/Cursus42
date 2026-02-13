/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 17:21:12 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-22 17:21:12 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
    isFrag = true; 
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "\033[94m" << this->getName() << " FragTrap default constructor called" << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    isFrag = true; 
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "\033[94m" << this->getName() << " FragTrap parameterized constructor called for " << Name << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) :ClapTrap(other) {
    std::cout << "\033[94m" << this->getName() << " FragTrap copy constructor called for " << Name << "\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void) {
std::cout << "\033[1;35m" << "FragTrap " << this->getName() << " ask positive high-fives " << "\033[0m" << std::endl;
}



FragTrap::~FragTrap() {
    std::cout << "\033[94m" << this->getName() << " FragTrap destructor called for " << Name << "\033[0m" << std::endl; 
}

