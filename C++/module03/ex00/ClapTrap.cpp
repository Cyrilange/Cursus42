/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-20 14:21:32 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-20 14:21:32 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()  : Name("") , HitPoints(10) , EnergyPoints(10) , AttackDamage(0)   {
    std::cout << "Default constuctor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name) , HitPoints(10) , EnergyPoints(10) , AttackDamage(0)   {
    std::cout << name << " Parameterized constuctor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : Name(other.Name), HitPoints(other.HitPoints),
      EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage) {
        std::cout << "Copy constructor called" << std::endl;
      }

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

std::string ClapTrap::getName() const {
    return this->Name;
}
int ClapTrap::getHitPoints() const {
    return this->HitPoints;
}
int ClapTrap::getEnergyPoints() const {
    return this->EnergyPoints;
}
int ClapTrap::getAttackDamage() const {
    return this->AttackDamage;
}

void ClapTrap::setName(std::string n) {
    this->Name = n;
}

void ClapTrap::setEnergyPoints(int ep) {
    this->EnergyPoints = ep;
}

void ClapTrap::setHitpoints(int hp) {
    this->HitPoints = hp;
}

void ClapTrap::setAttackDamage(int at) {
    this->AttackDamage = at;
}

void ClapTrap::attack(const std::string& target) {
    if (this->getEnergyPoints() > 1 ) {
        std::cout << "ClapTrap" << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << std::endl;
    }
    else {
        std::cout << "ClapTrap trying to attack " << target << " but does not have enought energy points" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
std::cout << "ClapTrap got " << amount << " points of damage" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->getHitPoints() > 1) {
        std::cout << "ClapTrap got " << amount << " points of repair" << std::endl;
    }
    else {
        std::cout << "ClapTrap cannot repair points" << std::endl;
    }

}

ClapTrap::~ClapTrap() {
    std::cout << "Desstuctor called" << std::endl;
}