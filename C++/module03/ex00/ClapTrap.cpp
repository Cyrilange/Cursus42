#include "ClapTrap.hpp"

ClapTrap::ClapTrap()  {
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

ClapTrap::~ClapTrap() {
    std::cout << "Desstuctor called" << std::endl;
}