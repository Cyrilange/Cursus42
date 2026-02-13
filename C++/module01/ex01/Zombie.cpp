/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:59:13 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:59:13 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("") {
  static  int index = 1;
    std::cout << "Default constructor numero: " << index++ << std::endl;
}

Zombie::Zombie(std::string n) : name(n) {
    std::cout << "The zombie called " << this->name << " is created!!!!" << std::endl;
};


void Zombie::setName(std::string name) {  this->name = name; std::cout << "The zombie called " << this->name << " is created!!!!" << std::endl;};
std::string Zombie::getName () const {return this->name;};

Zombie::~Zombie() {
std::cout << "Destructor called : ";
std::cout << "The zombie called " << this->name << " is destroyed!!!!" << std::endl;
};

void Zombie::announce( void ) {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
};