/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:53:00 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/30 00:59:23 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() :AMateria("cure") {}
Cure::Cure(const Cure& copy) : AMateria(copy) {}
Cure& Cure::operator=(const Cure& copy) {
	if (this != &copy) {
		AMateria::operator=(copy);
	}
	return *this;
}
Cure::~Cure() {}


AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}