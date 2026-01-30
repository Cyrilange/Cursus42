/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:18:45 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/30 00:35:26 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Unknow") {}
AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::AMateria(const AMateria& copy ) { *this = copy;}
AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}
std::string const & AMateria::getType() const { return this->_type;}
AMateria::~AMateria() {}