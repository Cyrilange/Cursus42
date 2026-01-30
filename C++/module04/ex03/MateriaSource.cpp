/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:35:50 by csalamit          #+#    #+#             */
/*   Updated: 2026/01/30 22:47:11 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : materiaSize(0) {
	for(int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	if (this != &copy) {
		*this = copy;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++) {
		if(this->_materia[i]) {
			delete this->_materia[i];
		}
	}
}
virtual void learnMateria(const std::string& type);
virtual AMateria* createMateria(const std::string& type);
void printMateria() const;