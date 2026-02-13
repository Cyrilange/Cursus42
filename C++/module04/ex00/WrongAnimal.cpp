/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-04 13:53:52 by csalamit          #+#    #+#             */
/*   Updated: 2025-10-04 13:53:52 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy constructor" << std::endl;
    *this = other;
};

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
    std::cout << "WrongAnimal constructor type" << std::endl;
 }


 WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
};

void WrongAnimal::makeSound() const {
std::cout << VIOLET_BOLD_ITALIC << "WrongAnimal sound" << RESET << std::endl;
}

const std::string& WrongAnimal::getType() const {
return type;
}

void WrongAnimal::setType(const std::string& _type) {
    this->type = _type;
};

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}