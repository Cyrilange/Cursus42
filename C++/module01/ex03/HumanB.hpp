/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:58:45 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:58:45 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
class Weapon;

class HumanB {
    private:
        std::string name;
        Weapon* weapon;
    
    public:
        HumanB(std::string n);
        HumanB();
        ~HumanB();
        std::string getName();
       
        void setName(std::string n);
        void setWeapon(Weapon& w);
       void attack();
        
};




#endif