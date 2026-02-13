/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-20 14:21:38 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-20 14:21:38 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap {

    public:

    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    std::string getName() const;

    //Getters
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;

    //Setters
    void setName(std::string n);
    void setEnergyPoints(int ep);
    void setHitpoints(int hp);
    void setAttackDamage(int at);
       
    //menber function
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    ~ClapTrap();


    protected:

        std::string Name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;
        bool isScav;
        bool isFrag;
        bool isDia;
};

#endif