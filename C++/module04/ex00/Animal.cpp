/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 14:10:51 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-28 14:10:51 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal copy constructor" << std::endl;
    *this = other;
};

Animal::Animal(const std::string& type) : type(type) {
    std::cout << "Animal constructor type" << std::endl;
 }


Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
};

void Animal::makeSound() const {
std::cout << GREEN_BOLD_ITALIC << "Animal sound" << RESET << std::endl;
}

const std::string& Animal::getType() const {
return type;
}

void Animal::setType(const std::string& _type) {
    this->type = _type;
};

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}