/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:24:21 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/30 01:01:49 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& copy) : AMateria(copy) {}
Ice& Ice::operator=(const Ice& copy) {
	if (this != &copy) {
		AMateria::operator=(copy);
	}
	return *this;
}
Ice::~Ice() {}


AMateria* Ice::clone() const {
	return new Ice(*this);
}
void Ice::use(ICharacter& target) {
	std::cout << "shoots an ice bolt at " << target.getName() << " *" << std::endl;
}