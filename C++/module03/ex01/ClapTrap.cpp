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

ClapTrap::ClapTrap()  : Name("") , HitPoints(10) , EnergyPoints(10) , AttackDamage(0), isScav(false)   {
    std::cout << "\033[94m" << "Default constuctor called" << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name) , HitPoints(10) , EnergyPoints(10) , AttackDamage(0) , isScav(false)  {
    std::cout << "\033[94m" << name << " Parameterized constuctor called" << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : Name(other.Name), HitPoints(other.HitPoints),
      EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage) {
        std::cout << "\033[94m" << "Copy constructor called" << "\033[0m" << std::endl;
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
    if (this->EnergyPoints > 0 && this->HitPoints > 0) {
        this->EnergyPoints--;
        std::cout << (isScav ? "ScavTrap " : "ClapTrap ")  << this->Name 
                  << " attacks " << target 
                  << " causing " << this->AttackDamage 
                  << (this->AttackDamage == 1 ? " point" : " points")
                  << " of damage, energy points now: " 
                  << this->EnergyPoints << std::endl;
    } else {
        if (this->HitPoints <= 0)
            std::cout << (isScav ? "ScavTrap " : "ClapTrap ")  << this->Name 
                      << " cannot attack because it has no hit points." << std::endl;
        else
            std::cout << (isScav ? "ScavTrap " : "ClapTrap ")  << this->Name 
                      << " cannot attack because it has no energy points." << std::endl;
    }
}


void ClapTrap::takeDamage(unsigned int amount) {
    this->HitPoints -= amount;
    if (this->HitPoints <= 0) this->HitPoints = 0;

    std::cout << (isScav ? "ScavTrap " : "ClapTrap ") << this->Name << " took " << amount << " damage, HP now: " << this->HitPoints << std::endl;
}



void ClapTrap::beRepaired(unsigned int amount) {
    if (this->EnergyPoints > 0 && this->HitPoints > 0) {
        this->HitPoints += amount;
        this->EnergyPoints--;
        std::cout << (isScav ? "ScavTrap " : "ClapTrap ")  << this->Name << " is repaired by " << amount << ", HP now: " << this->HitPoints << std::endl;
    } else {
        std::cout << (isScav ? "ScavTrap " : "ClapTrap ")  << this->Name << " cannot repair " << std::endl;
    }
}




ClapTrap::~ClapTrap() {
    std::cout << "\033[94m" << "Desstuctor called" << "\033[0m" << std::endl;
}