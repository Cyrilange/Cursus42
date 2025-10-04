/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:54:09 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:54:09 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Aanimal::Aanimal() {
    std::cout << "Animal default constructor called" << std::endl;
}

Aanimal::Aanimal(const Aanimal& other) {
    std::cout << "Animal copy constructor" << std::endl;
    *this = other;
};

Aanimal::Aanimal(const std::string& type) : type(type) {
    std::cout << "Animal constructor type" << std::endl;
 }


Aanimal& Aanimal::operator=(const Aanimal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
};

const std::string& Aanimal::getType() const {
return type;
}

void Aanimal::setType(const std::string& _type) {
    this->type = _type;
};

Aanimal::~Aanimal() {
    std::cout << "Animal destructor called" << std::endl;
}