/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:58:53 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:58:53 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t) : type(t) {};
Weapon::Weapon() {};

std::string Weapon::getType() {return this->type;};

void Weapon::setType(std::string t) { this->type = t;};

Weapon::~Weapon() {};