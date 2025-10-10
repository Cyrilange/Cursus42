/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:59:41 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:59:41 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string n) : name(n) {
    std::cout << "The zombie called " << this->name << " is created!!!!" << std::endl;
};

std::string Zombie::setName(std::string name) { return this->name = name;};
std::string Zombie::getName () const {return this->name;};

Zombie::~Zombie() {
std::cout << "The zombie called " << this->name << " is destroyed!!!!" << std::endl;
};

void Zombie::announce( void ) {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
};